#!/usr/bin/env python3
# -*- coding:utf-8 -*-
class Solution:
    def decompressRLElist(self, nums: [int]) -> [int]:
        ret = []
        for i in range(0, len(nums), 2):
            ret.extend([nums[i]] * nums[i + 1])
        return ret


def main():
    pass


if __name__ == '__main__':
    main()
