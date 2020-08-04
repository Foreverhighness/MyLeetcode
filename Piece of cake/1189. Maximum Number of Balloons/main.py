from collections import Counter
class Solution:
    def maxNumberOfBalloons(self, text: str) -> int:
        C = Counter(text)
        b, a, l, o, n = C['b'], C['a'], C['l'], C['o'], C['n']
        l //= 2
        o //= 2
        return min(b, a, l, o, n)
