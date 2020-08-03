#include <bits/stdc++.h>
#define DE(x) cout << #x << ": " << x << endl
using namespace std;
class Solution {
   public:
    string longestDupSubstring(string S) {
        using ll = long long;
        const int mod1 = 1e9 + 7;
        const int mod2 = 1e9 + 9;
        int n = S.length();
        string res;
        auto chk = [&](int len, bool flag) {
            unordered_set<int> seen1, seen2;
            ll rk1 = 0, rk2 = 0, base1 = 1, base2 = 1, sz = 26;
            for (int i = 0; i < len; ++i) {
                rk1 = (rk1 * sz + (S[i] - 'a')) % mod1;
                rk2 = (rk2 * sz + (S[i] - 'a')) % mod2;
            }
            for (int i = 1; i < len; ++i) {
                base1 = (base1 * sz) % mod1;
                base2 = (base2 * sz) % mod2;
            }
            seen1.insert(rk1);
            seen2.insert(rk2);
            for (int i = 0, j = len; j < n; ++i, ++j) {
                rk1 = (rk1 - (S[i] - 'a') * base1 % mod1 + mod1) % mod1;
                rk2 = (rk2 - (S[i] - 'a') * base2 % mod2 + mod2) % mod2;
                rk1 = (rk1 * sz + (S[j] - 'a')) % mod1;
                rk2 = (rk2 * sz + (S[j] - 'a')) % mod2;
                if (seen1.count(rk1) >= 1 && seen2.count(rk2) >= 1) {
                    if (flag) res = S.substr(i + 1, len);
                    return true;
                }
                seen1.insert(rk1);
                seen2.insert(rk2);
            }
            return false;
        };
        int l = 1, r = S.length();
        while (r - l > 1) {
            int m = (l + r) / 2;
            if (chk(m, false)) {
                l = m;
            } else {
                r = m;
            }
        }
        chk(l, true);
        return res;
    }
};

int main() {
    cout << Solution().longestDupSubstring("bcde") << endl;    // ""
    cout << Solution().longestDupSubstring("banana") << endl;  // "ana"
    return 0;
}