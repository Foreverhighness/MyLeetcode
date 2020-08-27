#!/usr/bin/env python3
# -*- coding:utf-8 -*-
class Solution:
    def matrixScore(self, A: [[int]]) -> int:
        n, m = len(A), len(A[0])
        for i in range(n):
            if A[i][0] == 0:
                for j in range(m):
                    A[i][j] ^= 1
        res, base = 0, 2 ** (m - 1)
        for col in zip(*A):
            numOfOne = col.count(1)
            res += base * max(numOfOne, n - numOfOne)
            base //= 2
        return res
        
def main():
    print(Solution().matrixScore([[0,0,1,1],[1,0,1,0],[1,1,0,0]]))

if __name__ == '__main__':
    main()
