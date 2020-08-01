from collections import Counter
class Solution:
    def rearrangeBarcodes(self, barcodes):
        n = len(barcodes)
        C = Counter(barcodes)
        barcodes.sort(key=lambda x: -10000 * C[x] + x)
        # print(barcodes)
        res = [None] * n
        res[::2]  = barcodes[:len(res[::2])]
        res[1::2] = barcodes[len(res[::2]):]
        return res
        # return chk(res)

def chk(a):
    for i in range(len(a) - 1):
        if a[i] == a[i + 1]:
            return False
    return True

s1 = Solution()
print(s1.rearrangeBarcodes([1,1,1,2,2,2]))
print(s1.rearrangeBarcodes([1,1,2]))
print(s1.rearrangeBarcodes([1,1,1,1,2,2,3,3]))
print(s1.rearrangeBarcodes([1]))
print(s1.rearrangeBarcodes([7,7,7,8,5,7,5,5,5,8]))
