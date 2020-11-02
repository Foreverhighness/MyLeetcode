#!/usr/bin/env python3
# -*- coding:utf-8 -*-
from typing import *
from collections import Counter, defaultdict
from math import *
from datetime import *
import sys
class Solution:
    def intersection(self, nums1: List[int], nums2: List[int]) -> List[int]:
        return list(set(nums1) & set(nums2))

def main():
    pass

if __name__ == '__main__':
    main()
