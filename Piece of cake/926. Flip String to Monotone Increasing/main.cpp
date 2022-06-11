#include <bits/stdc++.h>
using namespace std;
class Solution {
   public:
    int minFlipsMonoIncr(string s) {
        int n = s.size();
        int cnt[2][n + 1];
        memset(cnt, 0, sizeof cnt);
        for (int i = 0, zero = 0, one = 0; i < n; ++i) {
            if (s[i] == '0') {
                ++zero;
            } else {
                ++one;
            }
            cnt[0][i + 1] = zero;
            cnt[1][i + 1] = one;
        }
        int res = n;
        for (int i = 0; i <= n; ++i) {
            res = min(res, cnt[1][i] + (cnt[0][n] - cnt[0][i]));
        }
        return res;
    }
};

int main() { return 0; }