#!/usr/bin/env python3
# -*- coding:utf-8 -*-
class Solution:
    def thousandSeparator(self, n: int) -> str:
        s = str(n)
        L = []
        for i in range(len(s), 0, -3):
            L.append(s[max(0, i - 3):i])
        return '.'.join(L[::-1])


def main():
    pass


if __name__ == '__main__':
    main()
