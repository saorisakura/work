#!/usr/bin/env python
# -*- encoding: utf-8 -*-
# -*- Author:Seiya -*-
import random


def merge(src, temp, start, mid, end):
    i = start
    j = mid
    t = start
    while i != mid + 1 and j != end:
        if src[i] < src[j]:
            temp[t] = src[i]
            t, i = t + 1, i + 1
        else:
            temp[t] = src[j]
            t, j = t+1, j+1
    while i != mid:
        temp[t] = src[i]
        t, i = t + 1, i + 1
    while j != end:
        temp[t] = src[j]
        t, j = t + 1, j + 1
    i = start
    while i < end:
        src[i] = temp[i]
        i += 1


def mergesort(src, temp, start, end):
    if start > end:
        return None
    else:
        mid = int((0 + len(data_set)) / 2)
        mergesort(src, temp, start, mid)
        mergesort(src, temp, mid+1, end)
        merge(src, temp, start, mid, end)


data_set = list()
for item in range(10):
    data_set.append(item)

random.shuffle(data_set)
temp = list()
print(mergesort(data_set, temp, 0, len(data_set)))
# data_set = [5, 6, 7, 8, 9, 0, 1, 2, 3, 4]
# print(data_set)
# temp = [0]*len(data_set)
# mid = int((0+len(data_set))/2)
# merge(data_set, temp, 0, mid, len(data_set))
# print(data_set)
