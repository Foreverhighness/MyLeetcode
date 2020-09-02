#!/usr/bin/env python3
# -*- coding:utf-8 -*-
from collections import Counter
from math import factorial, sqrt


class Solution:
    def numSquarefulPerms(self, A: [int]) -> int:
        def isSquare(k):
            s = int(sqrt(k))
            for i in range(s - 1, s + 2):
                if i * i == k: return True
            return False

        from functools import lru_cache

        @lru_cache(None)
        def dp(prv, T):
            if len(T) == 0: return 1
            ret = 0
            for i in range(len(T)):
                if (i == 0 or T[i - 1] != T[i]) and isSquare(T[i] + prv):
                    ret += dp(T[i], T[:i] + T[i + 1:])
            return ret

        A.sort()
        res = 0
        for i in range(len(A)):
            if i == 0 or A[i - 1] != A[i]:
                res += dp(A[i], tuple(A[:i] + A[i + 1:]))
        return res


def main():
    print(Solution().numSquarefulPerms([1, 17, 8]))
    print(Solution().numSquarefulPerms([2, 2, 2]))


if __name__ == '__main__':
    main()
