class Solution:
    def heightChecker(self, h: List[int]) -> int:
        t = h[:]
        t.sort()
        res = 0
        for i in range(len(h)):
            if t[i] != h[i]:
                res += 1
        return res