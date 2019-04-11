#!/usr/bin/env python
# -*- encoding: utf-8 -*-
# -*- Author:Seiya -*-


def gen_next(str):
    length = len(str)
    str_list = list(str)
    slow = -1
    next = [None] * length
    next[0] = -1
    quick = 1
    while quick < length:
        while slow > -1 and str_list[slow + 1] != str_list[quick]:
            slow = next[slow]

        if str_list[slow + 1] == str_list[quick]:
            slow += 1

        next[quick] = slow
        quick += 1

    return next


print(gen_next("abbcabcaabbcaa"))
