from collections import *
class Solution:
    def isPossibleDivide(self, nums: List[int], k: int) -> bool:
        C = Counter(nums)
        S = list(set(nums))
        S.sort()
        for x in S:
            t = C[x]
            if t == 0:
                continue
            elif t < 0:
                return False
            for i in range(k):
                xn = x + i
                if C[xn] < t:
                    return False
                C[xn] -= t
        return True

