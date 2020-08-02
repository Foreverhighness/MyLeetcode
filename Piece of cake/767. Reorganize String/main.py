from collections import Counter
class Solution:
    def reorganizeString(self, S: str) -> str:
        S = list(S)
        n = len(S)
        C = Counter(S)
        def chk(a):
            for i in range(len(a) - 1):
                if a[i] == a[i + 1]:
                    return False
            return True
        S.sort(key=lambda x: -500 * C[x] + ord(x))
        res = [None] * n
        res[::2]  = S[:len(res[::2])]
        res[1::2] = S[len(res[::2]):]
        if chk(res):
            return res
        else:
            return ''


