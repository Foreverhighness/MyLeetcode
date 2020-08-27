# !/usr/bin/python3
# -*- coding: utf-8 -*-
class Solution:
    def judgeCircle(self, moves: str) -> bool:
        C = Counter(moves)
        return C['R'] == C['L'] and C['U'] == C['D']


def main():
    pass

if __name__ == '__main__':
    main()

