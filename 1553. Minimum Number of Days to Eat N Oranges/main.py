#!/usr/bin/env python3
# -*- coding:utf-8 -*-
class Solution:
    def minDays(self, n: int) -> int:
        from functools import lru_cache

        @lru_cache(None)
        def dp(n):
            if n <= 2:
                return n
            return min(dp(n // 2) + n % 2, dp(n // 3) + n % 3) + 1

        return dp(n)


def main():
    pass


if __name__ == '__main__':
    main()
