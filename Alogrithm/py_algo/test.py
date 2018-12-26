#!/usr/bin/env python
# -*- encoding: utf-8 -*-
# -*- Author:Seiya -*-
import time


class Person(object):
    _num = 0

    def __init__(self, name):
        Person._num += 1
        self.name = name
        print("Person {}: {} created.".format(id(self), self.name))

    def __del__(self):
        Person._num -= 1
        print("Person {}: {} deleted.".format(id(self), self.name))

    @staticmethod
    def num():
        return Person._num


a = Person("liyang")
print(Person.num())
b = Person("zhenzhen")
print(Person.num())
del b
print(Person.num())
time.sleep(10)
