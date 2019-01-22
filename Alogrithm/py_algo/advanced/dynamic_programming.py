#!/usr/bin/env python
# -*- encoding: utf-8 -*-
# -*- Author:Seiya -*-
import numpy
import sys
sys.setrecursionlimit(100000000)

data_set = [2, 2, 4, 6, 3]
n = len(data_set)
w = 9

results_1 = numpy.zeros((n, w))
results_2 = numpy.zeros((n, w))


def bag_by_backtracking(index=0, cw=0):
    if cw == w or index == n - 1:  # 已经达到最大值或者所有物品已经放入背包
        print(index, cw)
        return

    bag_by_backtracking(index+1, cw)  # 不放入index位置的物品
    if cw + data_set[index] <= w:
        bag_by_backtracking(index+1, cw+data_set[index])  # 放入index位置的物品


def bag_by_dynamic_programming(index=0):
    results_2[0][0] = 1
    results_2[0][data_set[index]] = 1
    index = 1
    while index < n:
        # 不放入index位置的物品
        for j, elem in enumerate(results_2[index]):
            if results_2[index-1][j]:
                results_2[index][j] = 1

        # 放入index位置的物品
        for j, elem in enumerate(results_2[index]):
            if results_2[index-1][j] and j+data_set[index] < w:
                results_2[index][j+data_set[index]] = 1

        index += 1


bag_by_backtracking()
print(results_1)
bag_by_dynamic_programming()
print(results_2)
