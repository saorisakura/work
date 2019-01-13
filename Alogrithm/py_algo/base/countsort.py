#!/usr/bin/env python
# -*- encoding: utf-8 -*-
# -*- Author:Seiya -*-
import random


def csort(data, n):

    # 先确定计数的范围
    c = list()
    pos = 0
    max = 0
    while pos < n:
        if max < data[pos]:
            max = data[pos]
        pos += 1

    # 生成计数数组
    c = [0] * (max + 1)  #
    # 遍历data数据集
    pos = 0
    while pos < n:
        c[data[pos]] += 1
        pos += 1
    print(c)

    # 计数数组顺序求和
    pos = 1  #
    while pos < len(c):
        c[pos] = c[pos-1] + c[pos]
        pos += 1

    print(c)

    # 排序
    pos = n - 1
    new = [0] * n  #
    while pos >= 0:
        index = c[data_set[pos]] - 1  #
        c[data_set[pos]] -= 1
        new[index] = data_set[pos]
        pos -= 1

    print(new)


data_set = [2, 5, 3, 0, 2, 3, 0, 3]
print(data_set)
csort(data_set, len(data_set))

print("----------------------------------------")
print(sorted(data_set))

print(15 >> 1)
