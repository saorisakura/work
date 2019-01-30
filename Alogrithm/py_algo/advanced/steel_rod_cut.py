#!/usr/bin/env python
# -*- encoding: utf-8 -*-
# -*- Author:Seiya -*-
price_table = {1: 10,
                 2: 50,
                 3: 80,
                 4: 90,
                 5: 100,
                 6: 170,
                 7: 170,
                 8: 200,
                 9: 240,
                 10: 300
                 }


def max_price(t, n):
    prices = [-1] * n
    prices[0] = 0

    external_index = 1
    while external_index < n:
        internal_index = 1
        cur_max = -1
        while internal_index <= external_index:
            if cur_max < t[internal_index] + prices[external_index-internal_index]:
                cur_max = t[internal_index] + prices[external_index-internal_index]
            internal_index += 1
        prices[external_index] = cur_max
        external_index += 1

    print(prices)


max_price(price_table, len(price_table))
