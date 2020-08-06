#!/usr/bin/env python3
# -*- coding:utf-8 -*-
class Solution:
    def maxSizeSlices(self, slices: [int]) -> int:
        from functools import lru_cache
        @lru_cache(None)
        def dp(left, right, need):
            if need == 1: return max(slices[left:right])
            if 2 * need - 1 > right - left: return int(-1e9)
            return max(slices[left] + dp(left + 2, right, need - 1), dp(left + 1, right, need))
        n = len(slices)
        return max(dp(0, n - 1, n // 3), dp(1, n, n // 3))

def main():
    pass

if __name__ == '__main__':
    main()