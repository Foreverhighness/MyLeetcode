#!/usr/bin/env python3
# -*- coding:utf-8 -*-
from typing import *
from collections import Counter

class Solution:
    def commonChars(self, A: List[str]) -> List[str]:
        return reduce(lambda x, y: x & y, map(Counter, A)).elements()

def main():
    pass

if __name__ == '__main__':
    main()
