#!/usr/bin/env python3
# -*- coding:utf-8 -*-
from typing import *
class Solution:
    def isNumber(self, s: str) -> bool:
        r = re.match(r'^\s*[+-]?((\d+(\.\d*)?)|(\.\d+))([eE][+-]?\d+)?\s*$', s)
        def charSet(ch):
            if ch == ' ': return 'b'          # blank
            elif ch in '+-': return 's'       # sign
            elif '0' <= ch <= '9': return 'd' # nums
            elif ch == '.': return '.'        # dot
            elif ch in 'Ee': return 'e'       # exponent
            else: return 'invaild'            # invaild

        state = [
            { 'b': 0, 's': 1, 'd': 2, '.': 4, }, # 0. start blank
            { 'd': 2, '.': 4, },                 # 1. sign before exponent
            { 'b': 8, 'd': 2, '.': 3, 'e': 5, }, # 2. numbers before exponent
            { 'b': 8, 'd': 3, 'e': 5, },         # 3. float
            { 'd': 3, },                         # 4. only dot
            { 's': 6, 'd': 7, },                 # 5. exponent
            { 'd': 7, },                         # 6. sign after exponent
            { 'b': 8, 'd': 7, },                 # 7. numbers after exponent
            { 'b': 8, },                         # 8. end blank
        ]

        cur = 0
        for ch in s:
            Type = charSet(ch)
            if Type not in state[cur]:
                return False
            cur = state[cur][Type]
        return cur in (2, 3, 7, 8)


def main():
    pass


if __name__ == '__main__':
    main()
