#!/usr/bin/env python
# -*- encoding: utf-8 -*-
# -*- Author:Seiya -*-
import random


def qsort(data, l, r):
    stack = []
    while True:
        i = l
        j = r
        while True:
            while i != r and data[i] <= data[l]:
                i += 1
            while j != l and data[j] >= data[l]:
                j -= 1
            if i < j:
                data[i], data[j] = data[j], data[i]
            else:
                break
        data[l], data[j] = data[j], data[l]
        if j-1 < l and j+1 > r:
            if stack:
                l, r = stack.pop(0)
            else:
                break
        else:
            if j-1 >= l and j+1 <= r:
                """ 注意此处的临界值判断是否加入堆栈中，说明最后定位的j距离左右端点为1，此时需要将另一半大的范围入栈"""
                stack.insert(0, (j+1, r))
                r = j-1
            elif j+1 > r:
                r = j-1
            else:
                l = j+1


# data_set = [2, 9, 5, 4, 8, 1, 3, 0, 6, 7]
data_set = list()
for item in range(100000):
    data_set.append(item)

random.shuffle(data_set)
print(data_set)
qsort(data_set, 0, len(data_set)-1)
print(data_set)
