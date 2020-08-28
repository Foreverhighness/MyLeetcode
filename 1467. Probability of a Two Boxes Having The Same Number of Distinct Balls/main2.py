#!/usr/bin/env python3
# -*- coding:utf-8 -*-
class Solution:
    def getProbability(self, balls: [int]) -> float:
        n = len(balls)
        left, right = [0] * n, [0] * n
        cnt = 0
        def calc(L):
            ret = factorial(sum(L))
            for i in L:
                ret //= factorial(i)
            return ret
        def dfs(idx):
            if idx == n:
                if len(left) == len(right) and left.count(0) == right.count(0):
                    cnt += calc(left) * calc(right)
                return
            for i in range(balls[idx] + 1):
                left[idx] = i
                right[idx] = balls[idx] - i
                dfs(idx + 1)
        dfs(0)
        return cnt / calc(balls)


def main():
    pass

if __name__ == '__main__':
    main()
