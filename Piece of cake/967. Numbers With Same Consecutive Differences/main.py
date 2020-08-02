class Solution:
    def numsSameConsecDiff(self, N: int, K: int) -> [int]:
        res = []
        def dfs(n):
            nonlocal cur, res
            if n == 0:
                res.append(cur)
                return
            t = cur % 10
            if 0 <= t - K <= 9:
                cur = cur * 10 + t - K
                dfs(n - 1)
                cur //= 10
            if K != 0 and 0 <= t + K <= 9:
                cur = cur * 10 + t + K
                dfs(n - 1)
                cur //= 10
        start = 1 if N != 1 else 0
        for i in range(start, 10):
            cur = i
            dfs(N - 1)
        return res
