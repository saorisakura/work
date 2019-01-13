#!/usr/bin/env python
# -*- encoding: utf-8 -*-
# -*- Author:Seiya -*-
import hashlib


def hash_(str):
    hashobj = hashlib.md5()
    hashobj.update(str)
    digest = hashobj.hexdigest()
    return digest


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


def rk(str, substr):
    """BF利用哈希算法优化"""
    substr_len = len(substr)
    substr_count = len(str) - substr_len + 1
    hash_list = list()
    count = 0
    while substr_count:
        hash_list.append(hash_((str[count:count+substr_len]).encode("utf-8")))
        substr_count -= 1
        count += 1
    if hash_(substr.encode("utf-8")) in hash_list:
        print("RK匹配成功")
    else:
        print("RK匹配失败")


str = "asdkfhkshdfbbakshdfk"
substr = "bba"
# print(str)
# print(substr)
# bf(str, substr)
rk(str, substr)
