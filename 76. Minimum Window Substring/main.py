# !/usr/bin/python3 
# -*- coding: utf-8 -*-

def chk(d):
    for v in d.values():
        if v == 0: return False
    return True

def minWindow(s: str, t: str) -> str:
    i, j, ansi, ansj, l = 0, 0, 0, 0, len(s)
    t = set(t)
    D = dict()
    nxti = []
    nxtidx = 0
    for k in t:
        D[k] = 0
    while j < l and s[j] not in t:
        j += 1
    i = j
    while j < l:
        ch = s[j]
        if ch not in t: 
            j += 1
            continue
        nxti.append(j)
        D[ch] += 1
        j += 1
        while self.chk(D):
            if ansj == 0 or ansj - ansi > j - i:
                ansi, ansj = i, j
                print(s[ansi:ansj])
            D[s[i]] -= 1
            i = nxti[nxtidx]
            nxtidx += 1
    return s[ansi:ansj]

def main():
    S = 'ADOBECODEBANC'
    T = 'ABC'
    print(minWindow)

if __name__ == "__main__":
    main()