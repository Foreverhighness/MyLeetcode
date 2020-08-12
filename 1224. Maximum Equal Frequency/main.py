#!/usr/bin/env python3
# -*- coding:utf-8 -*-
from collections import Counter


class Solution:
    def maxEqualFreq(self, nums: [int]) -> int:
        n = len(nums)
        if n <= 2:
            return n
        C = Counter(nums)

        def chk():
            if len(C) == 1:
                return True
            tmp = C.most_common()
            a, b, c, d = tmp[0][1], tmp[1][1], tmp[-1][1], tmp[-2][1]
            if a - c == 1 and a - b == 1:
                return True
            if c == 1 and a == d:
                return True
            return False

        for i, num in enumerate(reversed(nums)):
            if chk():
                return n - i
            C[num] -= 1
            if C[num] == 0:
                C.pop(num)
        return 2


def main():
    L = [[2, 2, 1, 1, 5, 3, 3, 5], [1, 1, 1, 2, 2, 2, 3, 3, 3, 4, 4, 4, 5], [
        1, 1, 1, 2, 2, 2], [10, 2, 8, 9, 3, 8, 1, 5, 2, 3, 7, 6]]
    for l in L:
        print(Solution().maxEqualFreq(l))


if __name__ == '__main__':
    main()
