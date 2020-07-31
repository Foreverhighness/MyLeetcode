from collections import Counter
class Solution:
    def maxFreq(self, s: str, maxLetters: int, minSize: int, maxSize: int) -> int:
        n = len(s)
        res = 0
        for L in range(minSize, maxSize + 1):
            l, r = 0, L
            C = Counter(s[l:r])
            Cs = Counter()
            while True:
                if len(C) <= maxLetters:
                    Cs[s[l:r]] += 1
                if r == n: break
                C[s[r]] += 1
                r += 1
                C[s[l]] -= 1
                if C[s[l]] == 0:
                    del C[s[l]]
                l += 1
            cand = 0 if len(Cs) == 0 else max(Cs.values())
            res = max(res, cand)
        return res
