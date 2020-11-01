#!/usr/bin/env python3
# -*- coding:utf-8 -*-
from typing import *
from collections import Counter, defaultdict
from math import *
from datetime import *
import sys
class Solution:
    def wordBreak(self, s: str, wordDict: List[str]) -> List[str]:
        @lru_cache(None)
        def backtrack(index: int) -> List[List[str]]:
            if index == len(s):
                return [[]]
            ans = []
            for i in range(index + 1, len(s) + 1):
                word = s[index:i]
                if word in wordSet:
                    for nextWordBreak in backtrack(i):
                        ans.append(nextWordBreak.copy() + [word])
            return ans

        wordSet = set(wordDict)
        return [" ".join(words[::-1]) for words in backtrack(0)]

def main():
    pass

if __name__ == '__main__':
    main()
