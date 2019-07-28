import multiprocessing
import time

import redis

from cfg import PROXY_REDIS_CFG
from common import redis_pool
proxy_redis_cfg = PROXY_REDIS_CFG['dev']
redis_pool.init_redis(proxy_redis_cfg)

TEST = {
    # 测试   {'test1': 20} 每秒产生的令牌数量
    'all': {
        'test1': {'test1': 20},
        'test2': {'test2': 20},
        'test3': {'test3': 20},
        'test4': {'test4': 20},
        'test5': {'test5': 200},
        'test6': {'test6': 20},
    }
}

class RedisTokenCache():
    def __init__(self, host, port, db=0, max_connections=None):
        self.redis = redis.Redis(
            connection_pool=redis.ConnectionPool(host=host, port=port, db=db, max_connections=max_connections))
    def fetchToken(self, rate=100, count=1, expire=2, key=None):
        date = str(int(time.time()))
        key = ":".join([key, date])
        try:
            current = self.redis.get(key)
            if int(current if current else "0") > rate and current < 0:
                raise Exception("to many requests in current second: %s" % date)
            else:
                with self.redis.pipeline() as p:
                    p.multi()
                    p.incr(key, count)
                    p.expire(key, int(expire if expire else "1"))
                    p.execute()
                    return True
        except:
            return False


class DistributeRateLimiter():
    def __init__(self, cache, ):
        self.cache = cache

    def acquire(self, rate=None, key=None):
        try:
            return self.cache.fetchToken(rate=rate, key=key)
        except:
            return True


token_cache = RedisTokenCache(host='localhost', port=6379,db=0)
limiter = DistributeRateLimiter(cache=token_cache)
result_dict = TEST["all"]

def job():
    while 1:
        for result in result_dict.values():
            key = tuple(result.keys())[0]
            rate = tuple(result.values())[0]
            if not limiter.acquire(rate, key):
                print('限流')
            else:
                print('正常')

def run():
    threads = [multiprocessing.Process(target=job) for i in range(10)]
    for thread in threads:
        thread.start()


if __name__ == '__main__':
    run()