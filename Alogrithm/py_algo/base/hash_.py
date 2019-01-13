#!/usr/bin/env python
# -*- encoding: utf-8 -*-
# -*- Author:Seiya -*-
import hashlib

hashobj = hashlib.md5()
hashobj.update("liyang".encode("utf-8"))
hash = hashobj.hexdigest()
print(hash)
for i in range(len(hash)):
    print(hash[i])
    print("----------------------")
    print(ord(hash[i]))
    print()
# md5 = hashlib.md5()  # 创建一个MD5加密对象
# md5.update("JGood is a handsome boy".encode("utf-8"))  # 更新要加密的数据
# print(md5.digest())  # 加密后的结果（二进制）
# print(md5.hexdigest())  # 加密后的结果，用十六进制字符串表示。
# print(md5.hexdigest())  # 加密后的结果，用十六进制字符串表示。
# print('block_size:', md5.block_size)
# print('digest_size:', md5.digest_size)


"""
# hashlib.md5(data)函数中，data参数的类型应该是bytes
# hash前必须把数据转换成bytes类型
>>> from hashlib import md5
File "<stdin>", line 1, in <module>
>>> c = md5("helloworld")
TypeError: Unicode-objects must be encoded before hashing
>>> c = md5("helloworld".encode("utf-8"))
>>> print(c.hexdigest())
fc5e038d38a57032085441e7fe7010b0
"""