#!/usr/bin/env python
# -*- encoding: utf-8 -*-
# -*- Author:Seiya -*-
import random
import sys

sys.setrecursionlimit(10000)


def merge(data, start, mid, end):
    left_set_num = mid - start + 1
    right_set_num = end - mid
    left = list()
    right = list()
    for i in range(left_set_num):
        left.append(data[start+i-1])

    for j in range(right_set_num):
        right.append(data[mid+j])

    i = 0
    j = 0
    k = start
    while k <= end:
        if left[i] <= right[j]:
            data[k] = left[i]
            i = i + 1
        else:
            data[k] = right[j]
            j = j + 1


def mergesort(src, start, end):
    if start < end:
        mid = int((start + end) / 2)
        mergesort(src, start, mid)
        mergesort(src, mid+1, end)
        merge(src, start, mid, end)


data_set = list()
for item in range(10):
    data_set.append(item)

random.shuffle(data_set)
print(mergesort(data_set, 0, len(data_set)))
# data_set = [5, 6, 7, 8, 9, 0, 1, 2, 3, 4]
# print(data_set)
# temp = [0]*len(data_set)
# mid = int((0+len(data_set))/2)
# merge(data_set, temp, 0, mid, len(data_set))
# print(data_set)
