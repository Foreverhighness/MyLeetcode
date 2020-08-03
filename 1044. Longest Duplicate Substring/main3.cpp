#include <bits/stdc++.h>
#define DE(x) cout << #x << ": " << x << endl
using namespace std;
class Solution {
   public:
    string longestDupSubstring(string S) {
        using ll = long long;
        const ll mod = 1e9 + 7;
        const ll sz = 26;
        int n = S.length();
        string res;
        auto chk = [&](int len, bool flag) {
            unordered_set<int> seen;
            ll rk = 0, base = 1;
            for (int i = 0; i < len; ++i) {
                rk = (rk * sz + (S[i] - 'a')) % mod;
                base = (base * sz) % mod;
            }
            seen.insert(rk);
            for (int i = 0, j = len; j < n; ++i, ++j) {
                rk = (rk * sz - (S[i] - 'a') * base % mod + mod + S[j] - 'a') %
                     mod;
                if (seen.count(rk) >= 1) {
                    if (flag) res = S.substr(i + 1, len);
                    return true;
                }
                seen.insert(rk);
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
    freopen("in.txt", "r", stdin);
    string s;
    while (cin >> s)
        cout << Solution().longestDupSubstring(s)
             << endl;  // ["", "ana", "aeeebaabd", "luqvg",
                       // "babaaaabbbbabbababbabbbababbbb"]
    return 0;
}