#include <bits/stdc++.h>
using namespace std;
class Solution {
    int gcd(int a, int b) {
        if (a == 0) return b;
        if (b == 0) return a;
        if (a < 0) a = -a;
        if (b < 0) b = -b;
        return a % b == 0 ? b: gcd(b, a % b);
    }
public:
    int maxPoints(vector<vector<int>>& p) {
        int n = p.size(), res = 0;
        if (n <= 2) return n;
        for (int i = 0; i < n; ++i) {
            int lx = p[i][0], ly = p[i][1], dup = 1, cnt = 0;
            map<pair<int, int>, int> ma;
            for (int j = i + 1; j < n; ++j) {
                int rx = p[j][0], ry = p[j][1];
                if (lx == rx && ly == ry) {
                    ++dup;
                } else {
                    int A = ry - ly, B = lx - rx, g = gcd(A, B);
                    A /= g, B /= g;
                    if (A < 0) A = -A, B = -B;
                    ma[make_pair(A, B)] += 1;
                    cnt = max(cnt, ma[make_pair(A, B)]);
                }
            }
            res = max(res, dup + cnt);
        }
        return res;
    }
};