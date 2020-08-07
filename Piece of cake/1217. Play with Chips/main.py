#!/usr/bin/env python3
# -*- coding:utf-8 -*-
class Solution:
    def minCostToMoveChips(self, chips: [int]) -> int:
        odd, even = 0, 0
        for x in chips:
            if x & 1:
                odd += 1
            else:
                even += 1
        return min(odd, even)


def main():
    pass


if __name__ == '__main__':
    main()
