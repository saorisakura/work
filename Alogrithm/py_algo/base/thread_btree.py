#!/usr/bin/env python
# -*- encoding: utf-8 -*-
# -*- Author:Seiya -*-


def threadify(T):
    head = BTnode("/")
    head.lchild = T
    head.ltag = 1
    head.rchild = None
    head.rtag = 1
    prior = head
    q = T
    top = -1
    stack = []
    while q is not None or top != -1:
        while q:
            stack.insert(0, q)
            q = q.lchild
            top += 1

        q = stack.pop(0)
        top -= 1
        """start binary tree threadify"""
        if q.lchild is None:
            q.ltag = 1
            q.lchild = prior
        else:
            q.ltag = 0

        if prior.rchild is None:
            prior.rtag = 1
            prior.rchild = q
        else:
            prior.rtag = 0
        prior = q
        """end"""
        q = q.rchild
    prior.rchild = head
    prior.rtag = 1
    t = head.lchild
    while t:
        print(t.data)
        t = t.rchild


class BTnode(object):

    def __init__(self, data, left=None, right=None):
        self.lchild = left
        self.ltag = 0
        self.rchild = right
        self.rtag = 0
        self.data = data


T = BTnode(5)
for i in [2, 1, 4, 3, 7, 6, 9, 8]:
    new = BTnode(i)
    p = T
    while True:
        if new.data < p.data:
            # 移动到左子树
            if p.lchild:
                p = p.lchild
            else:
                p.lchild = new
                break
        else:
            # 移到右子树
            if p.rchild:
                p = p.rchild
            else:
                p.rchild = new
                break

print("start threadify")
threadify(T)
