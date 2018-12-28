#!/usr/bin/env python
# -*- encoding: utf-8 -*-
# -*- Author:Seiya -*-
import random


class Node(object):
    _num = 0

    def __init__(self, data, link=None):
        self.data = data
        self.link = link


data_set = list()
for item in range(10):
    data_set.append(item)

random.shuffle(data_set)
head = Node(None)
q = head
for item in data_set:
    p = Node(item)
    q.link = p
    q = p


q = head
while q:
    print(q.data)
    q = q.link
