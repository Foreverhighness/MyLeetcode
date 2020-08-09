#!/usr/bin/env python3
# -*- coding:utf-8 -*-
class Solution:
    def restoreIpAddresses(self, s: str) -> [str]:
        n = len(s)
        res = []

        def dfs(m, indices):
            i = indices[-1]
            if m + 1 <= n - i <= 3 * (m + 1):
                if m == 0:
                    if 0 <= int(s[i:n]) <= 255 and str(int(s[i:n])) == s[i:n]:
                        indices.append(n)
                        t = '.'.join(s[indices[i]:indices[i + 1]]
                                     for i in range(len(indices) - 1))
                        indices.pop(-1)
                        res.append(t)
                    return
                j = i + 1
                while j < n and 0 <= int(s[i:j]) <= 255 and str(int(s[i:j])) == s[i:j]:
                    indices.append(j)
                    dfs(m - 1, indices)
                    indices.pop(-1)
                    j += 1
            else:
                return
        dfs(3, [0])
        return res


def main():
    print(Solution().restoreIpAddresses('25525511135'))


if __name__ == '__main__':
    main()
