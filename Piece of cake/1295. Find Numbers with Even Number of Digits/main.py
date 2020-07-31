class Solution:
    def findNumbers(self, nums: List[int]) -> int:
        t = [len(str(x)) for x in nums]
        res = 0
        for i in t:
            if i % 2 == 0:
                res += 1
        return res