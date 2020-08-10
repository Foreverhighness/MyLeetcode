#include <bits/stdc++.h>
using namespace std;
class Solution {
   public:
    int longestAwesome(string s) {
        const int inf = 0x3f3f3f3f;
        int idx[1 << 10], n = s.size(), res = 0, cur = 0;
        memset(idx, inf, sizeof idx);
        idx[cur] = -1;
        for (int i = 0; i < n; ++i) {
            int x = s[i] - '0';
            cur ^= 1 << x;
            if (idx[cur] == inf) idx[cur] = i;
            res = max(res, i - idx[cur]);
            for (int j = 1; j < 1 << 10; j <<= 1)
                res = max(res, i - idx[cur ^ j]);
        }
        return res;
    }
};

int main() { return 0; }