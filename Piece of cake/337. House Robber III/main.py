from functools import lru_cache
from sys import setrecursionlimit
# Definition for a binary tree node.
class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

class Solution:
    def rob(self, root: TreeNode) -> int:
        setrecursionlimit(int(1e6))
        @lru_cache(None)
        def dp(cur, can):
            if cur is None: return 0
            ret = dp(cur.left, True) + dp(cur.right, True)
            if can:
                ret = max(ret, dp(cur.left, False) + dp(cur.right, False) + cur.val)
            return ret
        return dp(root, True)
