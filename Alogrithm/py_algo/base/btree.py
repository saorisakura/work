#!/usr/bin/env python
# -*- encoding: utf-8 -*-
# -*- Author:Seiya -*-


class BTnode(object):

    def __init__(self, data, lchild=None, rchild=None):
        self.data = data
        self.lchild = lchild
        self.rchild = rchild


T = BTnode(5)
for i in [1, 2, 3, 4, 6, 7, 8, 9]:
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
# 中序遍历
p = T
top = -1
stack = []
stack.insert(0, p)
p = p.lchild
top += 1
while p is not None or top != -1:
    while p:
        stack.insert(0, p)
        p = p.lchild
        top += 1

    p = stack[0]
    stack.pop(0)
    top -= 1
    print(p.data)
    p = p.rchild

print("----------------------------")
# 前序遍历
p = T
top = -1
stack = []
print(p.data)
stack.insert(0, p)
p = p.lchild
top += 1
while p is not None or top != -1:
    while p:
        print(p.data)
        stack.insert(0, p)
        p = p.lchild
        top += 1

    p = stack[0]
    stack.pop(0)
    top -= 1
    p = p.rchild