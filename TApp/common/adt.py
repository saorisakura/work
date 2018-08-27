#!/usr/bin/env python
# -*- encoding: utf-8 -*-
# -*- Author:Seiya -*-
import datetime


class Person(object):
    _num = 0

    def __init__(self):
        Person._num += 1

    @classmethod
    def sum(cls):
        return cls._num

    def __del__(self):
        Person._num -= 1


class Staff(Person):
    _id_num = 0

    def __init__(self):
        super(Staff, self).__init__()


class Student(Person):
    _id_num = 0

    def __init__(self):
        super(Student, self).__init__()


if __name__ == '__main__':

    class HealthCheck(object):
        _instance = None

        def __new__(cls, *args, **kwargs):
            if not HealthCheck._instance:
                HealthCheck._instance = super(HealthCheck, cls).__new__(cls, *args, **kwargs)
            return HealthCheck._instance

        def __init__(self):
            self.servers = []
            self.__dict__["Author"] = "liyang"

        def add(self):
            self.servers.append("1")
            self.servers.append("2")
            self.servers.append("3")
            self.servers.append("4")

        def change(self):
            self.servers.pop()
            self.servers.append("5")


    h1 = HealthCheck()
    h2 = HealthCheck()
    print(h1)
    print(h2)
    h1.add()
    print(h1.servers)
    print(h1.__dict__)
    print(h2.servers)
    print(h2.__dict__)

    for i in range(4):
        print(h1.servers[i])

    h2.change()
    for i in range(4):
        print(h2.servers[i])

    print(HealthCheck.__dict__)
    """
    C:\Users\liyan\PycharmProjects\work-python3\venv\Scripts\python.exe C:/Users/liyan/PycharmProjects/TApp/common/adt.py
<__main__.HealthCheck object at 0x00000294D5857A58>
<__main__.HealthCheck object at 0x00000294D5857A58>
['1', '2', '3', '4']
{'servers': ['1', '2', '3', '4'], 'Author': 'liyang'}
['1', '2', '3', '4']
{'servers': ['1', '2', '3', '4'], 'Author': 'liyang'}
1
2
3
4
1
2
3
5
{'__module__': '__main__', '_instance': <__main__.HealthCheck object at 0x00000294D5857A58>, '__new__': <staticmethod object at 0x00000294D5857A20>, '__init__': <function HealthCheck.__init__ at 0x00000294D5870BF8>, 'add': <function HealthCheck.add at 0x00000294D5870A60>, 'change': <function HealthCheck.change at 0x00000294D58707B8>, '__dict__': <attribute '__dict__' of 'HealthCheck' objects>, '__weakref__': <attribute '__weakref__' of 'HealthCheck' objects>, '__doc__': None}

Process finished with exit code 0

    """
    # stu1 = Student()
    # stu2 = Student()
    # stu3 = Student()
    # staff1 = Staff()
    # staff2 = Staff()
    # print(staff2.sum())
    # del stu1
    # print(staff2.sum())
    #
    # import tornado.ioloop
    #
    # from tornado.gen import coroutine
    #
    # from tornado.concurrent import Future
    #
    #
    # @coroutine
    # def asyn_sum(a, b):
    #
    #     print("begin calculate:sum %d+%d" % (a, b))
    #
    #     future = Future()
    #
    #     future2 = Future()
    #
    #     iol = tornado.ioloop.IOLoop.instance()
    #
    #     print(future)
    #
    #     def callback(a, b):
    #         print("calculating the sum of %d+%d:" % (a, b))
    #
    #         future.set_result(a + b)
    #
    #         iol.add_timeout(iol.time() + 3, lambda f: f.set_result(None), future2)
    #
    #     iol.add_timeout(iol.time() + 3, callback, a, b)
    #
    #     result = yield future
    #
    #     print("after yielded")
    #
    #     print("the %d+%d=%d" % (a, b, result))
    #
    #     yield future2
    #
    #     print('after future2')
    #
    #
    # def main():
    #
    #     f = asyn_sum(2, 3)
    #
    #     print("main")

        # print(f)
        #
        # tornado.ioloop.IOLoop.instance().start()
    #
    #
    # if __name__ == "__main__":
    #     main()
