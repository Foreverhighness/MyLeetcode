#!/usr/bin/env python3
# -*- coding:utf-8 -*-
import sys


class Solution:
    def stoneGameV(self, stoneValue: [int]) -> int:
        Sum = [0] * (len(stoneValue) + 1)
        t = 0
        for i, v in enumerate(stoneValue):
            t += v
            Sum[i + 1] = t

        from functools import lru_cache
        sys.setrecursionlimit(1000000)

        @lru_cache(None)
        def dp(l, r):
            if r - l == 1: return 0
            res = 0
            for m in range(l + 1, r):
                sl, sr = Sum[m] - Sum[l], Sum[r] - Sum[m]
                if sl < sr:
                    res = max(res, sl + dp(l, m))
                elif sl > sr:
                    res = max(res, sr + dp(m, r))
                else:
                    res = max(res, sl + dp(l, m), sr + dp(m, r))
            return res

        return dp(0, len(stoneValue))


def main():
    pass


if __name__ == '__main__':
    main()
