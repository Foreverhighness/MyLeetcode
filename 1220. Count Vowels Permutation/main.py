#!/usr/bin/env python3
# -*- coding:utf-8 -*-
from sys import setrecursionlimit


class Solution:
    def countVowelPermutation(self, n: int) -> int:
        from functools import lru_cache
        mod = int(1e9 + 7)
        setrecursionlimit(int(1e5))

        @lru_cache(None)
        def dp(n, ch):
            if n == 1:
                return 1
            if ch == 0:
                return dp(n - 1, 1)
            if ch == 1:
                return dp(n - 1, 0) + dp(n - 1, 4)
            if ch == 2:
                return dp(n - 1, 3) + dp(n - 1, 4)
            if ch == 3:
                return dp(n - 1, 0)
            if ch == 4:
                return sum(dp(n - 1, i) for i in range(4))
        return sum(dp(n, i) for i in range(5)) % mod


def main():
    pass


if __name__ == '__main__':
    main()
