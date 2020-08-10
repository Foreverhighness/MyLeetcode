#!/usr/bin/env python3
# -*- coding:utf-8 -*-
class Solution:
    def minCost(self, n: int, cuts: [int]) -> int:
        from functools import lru_cache
        cuts.append(0)
        cuts.append(n)
        cuts.sort()

        @lru_cache(None)
        def dp(l, r):
            if r - l == 1:
                return 0
            return cuts[r] - cuts[l] + min(dp(l, m) + dp(m, r) for m in range(l + 1, r))
        return dp(0, len(cuts) - 1)


def main():
    pass


if __name__ == '__main__':
    main()
