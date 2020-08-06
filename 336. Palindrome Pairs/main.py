#!/usr/bin/env python3
# -*- coding:utf-8 -*-
class Solution:
    def palindromePairs(self, words: [str]) -> [[int]]:
        def isPalindrome(s):
            n = len(s)
            for i in range(n // 2):
                if s[i] != s[n - i - 1]:
                    return False
            return True
        dic = {word[::-1]: i for i, word in enumerate(words)}
        # print(dic)
        res = []
        for i, word in enumerate(words) :
            for l in range(len(word) + 1):
                # print(word, l)
                s1, s2 = word[:l], word[l:]
                if isPalindrome(s2) and s1 in dic:
                    j = dic[s1]
                    if j != i:
                        # print(f'({i}, {j}): {words[i]} + {words[j]}')
                        res.append([i, j])
                
                # l == 0 时, s1 == '',  s2 为 word[i], 此时如果存在 words[j] 是 words[i] 的反转，
                # 那么 words[i] 也将是 word[j] 的反转，结果为 word[j] + word[i].
                # 但在上面那个判断中，当 s1 == word[j], s2 == '' 时，会将这个结果包括进去，
                # 因此为了避免重复，对 l 进行特判。
                if l and isPalindrome(s1) and s2 in dic:
                    j = dic[s2]
                    if j != i:
                        # print(f'({j}, {i}): {words[j]} + {words[i]}')
                        res.append([j, i])
        return res

print(Solution().palindromePairs(["abcd","dcba","lls","s","sssll"]))
print(Solution().palindromePairs(["bat","tab","cat"]))
print(Solution().palindromePairs(["a",""]))