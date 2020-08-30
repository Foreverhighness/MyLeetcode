#!/usr/bin/env python3
# -*- coding:utf-8 -*-
class Solution:
    def reverseWords(self, s: str) -> str:
        return ' '.join([item[::-1] for item in s.split()])


def main():
    pass


if __name__ == '__main__':
    main()
