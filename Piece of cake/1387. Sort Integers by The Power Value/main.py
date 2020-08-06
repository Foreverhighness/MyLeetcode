class Solution:
    def getKth(self, lo: int, hi: int, k: int) -> int:
        from functools import lru_cache
        @lru_cache(None)
        def dp(x):
            if x == 1: return 0
            if x & 1:
                return dp(3 * x + 1) + 1
            else:
                return dp(x // 2) + 1
        res = list(range(lo, hi + 1))
        res.sort(key=lambda x: dp(x) * 10000 + x)
        return res[k - 1]
