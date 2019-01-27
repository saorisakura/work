#!/usr/bin/env python
# -*- encoding: utf-8 -*-
# -*- Author:Seiya -*-
import random

data_set = [x for x in range(20)]
# data_set = [9, 7, 3, 8, 1, 5, 0, 6, 2, 4]  # 防止j在if temp >= data_set[j]: break处为0 时产生死循环
random.shuffle(data_set)
print(data_set)


def heapify(data_set, n):
    i = n
    temp = data_set[i]
    j = 2 * i
    while j < len(data_set):
        if data_set[j] < data_set[j+1]:
            j = j + 1

        if temp >= data_set[j]:
            break

        data_set[j//2] = data_set[j]
        j = j * 2

    data_set[j//2] = temp


index = (len(data_set) - 1) // 2
while index >= 0:
    heapify(data_set, index)
    index = index - 1

print(data_set)
