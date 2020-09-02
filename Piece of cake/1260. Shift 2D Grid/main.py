#!/usr/bin/env python3
# -*- coding:utf-8 -*-
from typing import *


class Solution:
    def shiftGrid(self, grid: List[List[int]], k: int) -> List[List[int]]:
        n, m = len(grid), len(grid[0])
        ret = [[0] * m for i in range(n)]
        k %= n * m
        for i in range(n):
            for j in range(m):
                nxt = (i * m + j + k) % (n * m)
                ni, nj = nxt / m, nxt % m
                ret[ni][nj] = grid[i][j]
        return ret


class Solution1:
    def shiftGrid(self, grid: List[List[int]], k: int) -> List[List[int]]:
        n = len(grid)
        for i in range(k):
            grid = [grid[(i - 1) % n][-1:] + grid[i][:-1] for i in range(n)]
        return grid


def main():
    print(Solution().shiftGrid([[1, 2, 3], [4, 5, 6], [7, 8, 9]], 1))


if __name__ == '__main__':
    main()
