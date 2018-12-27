#!/usr/bin/env python
# -*- encoding: utf-8 -*-
# -*- Author:Seiya -*-


def bf(str, substr):
    i = 0
    p = str
    q = substr
    sub_len = len(q)
    while i < len(p) and p[i]:
        k = i
        j = 0
        while j < sub_len and q[j]:
            if p[k] == q[j]:
                k += 1
                j += 1
            else:
                j = 0
                k += 1

        if j == sub_len:
            print("匹配成功")
            return i
        else:
            i = i + 1


str = list("asdkfhkshdfbbakshdfk")
substr = list("bba")
print(str)
print(substr)
bf(str, substr)
