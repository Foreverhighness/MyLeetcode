# !/usr/bin/python3 
# -*- coding: utf-8 -*-
import math
class Solution:
    def cnt(self, x, A, B, lcm):
        return x // A + x // B - x // lcm
    def nthMagicalNumber(self, N: int, A: int, B: int) -> int:
        lo, hi, mod = min(A, B), int(1e14), int(1e9+7)
        lcm = A * B / math.gcd(A, B)
        while lo < hi:
            mi = (lo + hi) // 2
            if self.cnt(mi, A, B, lcm) < N: lo = mi + 1
            else: hi = mi 
        return lo % mod
        