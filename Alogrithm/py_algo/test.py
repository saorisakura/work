#!/usr/bin/env python
# -*- encoding: utf-8 -*-
# -*- Author:Seiya -*-
import time


class Rational(object):

    def __init__(self, num, den):
        self.num = num
        self.den = den

    def __add__(self, other):
        return Rational(self.num + other.num, self.den + other.den)

    def __sub__(self, other):
        return Rational(self.num - other.num, self.den - other.den)

    def __mul__(self, other):
        return Rational(self.num * other.num, self.den * other.den)

    def __floordiv__(self, other):
        return Rational(self.num * other.den, self.den + other.num)

    def __eq__(self, other):
        return self.den * other.num == self.num * other.den

    def __str__(self):
        return str(self.num) + "/" + str(self.den)


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
# time.sleep(1)

c = Rational(2, 3)
d = Rational(2, 3)

print("Rational number {}".format(c))
print("Rational number {}".format(d))
print("Rational number {}".format(c + d))
print("Rational number {}".format(c - d))
print("Rational number {}".format(c * d))
print("Rational number {}".format(c // d))
print("Rational number equal or not {}".format(c == d))
