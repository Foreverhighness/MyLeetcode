#!/usr/bin/env python3
# -*- coding:utf-8 -*-
from typing import *
from collections import Counter, defaultdict
from math import *
from datetime import *
import sys


class Solution:
    def uniqueOccurrences(self, arr: List[int]) -> bool:
        C = Counter(arr)
        C = Counter(list(C.values()))
        return max(list(C.values())) == 1


def main():
    pass


if __name__ == '__main__':
    main()
