#!/usr/bin/env python
# -*- encoding: utf-8 -*-
# -*- Author:Seiya -*-


class LListTypeError(ValueError):
    pass


class LList(object):

    def __init__(self, data, link=None):
        self.data = data
        self.link = link

    def prepend(self, node):
        p = LList(node)
        p.link = self.link
        self.link = p

    def append(self, node):
        p = self
        q = LList(node)
        if p.link is None:
            p.link = q
        else:
            while p.link is not None:
                p = p.link
        p.link = q


llist = LList(-1)
p = llist
for i in range(10):
    p.append(i)
for i in range(10):
    p.prepend(i)

while p:
    print(p.data)
    p = p.link
