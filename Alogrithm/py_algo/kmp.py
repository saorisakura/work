#!/usr/bin/env python
# -*- encoding: utf-8 -*-
# -*- Author:Seiya -*-


def gen_next(str):
    i, k, m = 0, -1, len(str)
    pnext = [-1] * m
    while i < m-1:
        a, b = str[i], str[k]
        if k == -1 or str[i] == str[k]:
            i, k = i+1, k+1
            pnext[i] = k
        else:
            k = pnext[k]
    return pnext


print(gen_next("abbcabcaabbcaa"))
