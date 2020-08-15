#!/usr/bin/env python3
# -*- coding:utf-8 -*-
import sys


class Solution:
    def removeBoxes(self, boxes: [int]) -> int:
        from functools import lru_cache
        sys.setrecursionlimit(1000000)

        @lru_cache(None)
        def dp(L, R, n):
            '''dp(L, R, n) 表示在 L 之前（不包括 L）有 n 个与 boxes[L] 相同的值时的最大值'''
            if R - L == 1:
                return (n + 1) * (n + 1)
            if boxes[L] == boxes[L + 1]:
                return dp(L + 1, R, n + 1)
            ret = (n + 1) * (n + 1) + dp(L + 1, R, 0)
            for m in range(L + 2, R):
                if boxes[L] == boxes[m]:
                    ret = max(ret, dp(L + 1, m, 0) + dp(m, R, n + 1))
            return ret

        for l in range(1, len(boxes) + 1):
            for i in range(0, len(boxes) - l + 1):
                for k in range(i + 1):
                    print(f'dp[{l},{i},{k}]={dp(i, i + l, k)}')
        return dp(0, len(boxes), 0)


def main():
    Solution().removeBoxes([1, 3, 2, 2, 2, 3, 4, 3, 1])
    # print(Solution().removeBoxes([
    #     1, 3, 2, 4, 4, 5, 2, 2, 4, 3, 2, 4, 3, 2, 5, 4, 3, 1, 1, 4,1,5,3,1,
    #     5, 1, 2, 5, 4, 4, 1, 3, 2, 5, 2
    # ]))


if __name__ == '__main__':
    main()
