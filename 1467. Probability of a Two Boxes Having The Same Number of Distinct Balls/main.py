#!/usr/bin/python3
# -*- encoding:utf8 -*-
from math import factorial

def C(n, m):
    return factorial(n) // factorial(m) // factorial(n - m)

def calc(ls, lc, rs, rc, idx, ball, cnt):
    # if ls > rs or (ls == rs and lc > rc):
    #     return calc(rs, rc, ls, lc, idx, ball, cnt)
    # if dp[ls][lc][rs][rc][idx] != 0: 
    #     return  dp[ls][lc][rs][rc][idx]
    if idx == N:
        if lc == rc:
            # dp[ls][lc][rs][rc][idx] = 1
            # return dp[ls][lc][rs][rc][idx]
            return cnt
        else:
            return 0
    # if abs(lc-rc) > N-idx:
    #     return 0
    sz = ball[idx]
    res = 0
    for la in range(sz+1):
        ra = sz - la
        nls, nrs = ls-la, rs-ra
        if nls < 0 or nrs < 0:
            continue
        nlc, nrc = lc, rc
        if la != 0: nlc+=1
        if ra != 0: nrc+=1
        res += calc(nls,nlc, nrs,nrc,idx+1, ball, cnt * C(ls, la) * C(rs, ra))
    return res
    # dp[ls][lc][rs][rc][idx] = res
    # return dp[ls][lc][rs][rc][idx]


balls = [[1, 1], [2, 1, 1], [1, 2, 1, 2], [3, 2, 1], [6, 6, 6, 6, 6, 6], [6, 6, 6, 6, 6, 6, 6, 6]]
ans   = [2, 8, 108, 18]
for ball in balls:
    # dp = [[[[[0]*10]*10]*30]*10]*30
    N = len(ball)
    s = sum(ball)
    s //= 2
    print(calc(s, 0, s, 0, 0, ball, 1))

# 2
# 8
# 108
# 18
# 2411897898864801970022400
# 147087536571653860012538977197543014400