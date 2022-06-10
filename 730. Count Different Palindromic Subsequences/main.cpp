#include <bits/stdc++.h>
using namespace std;
class Solution {
   public:
    int countPalindromicSubsequences(string s) {
        constexpr int mod = 1e9 + 7;
        int n = s.size();
        vector<vector<int>> dp(n + 1, vector<int>(n + 1));
        vector<int> prv(n, -1), nxt(n, n);

        vector<int> pos(4, -1);
        for (int i = 0; i < n; ++i) {
            int ch = s[i] - 'a';
            if (pos[ch] != -1) {
                prv[i] = pos[ch];
                nxt[pos[ch]] = i;
            }
            pos[ch] = i;
            dp[i][i + 1] = 1;
        }

        for (int len = 2; len <= n; ++len) {
            for (int l = 0; l + len <= n; ++l) {
                int r = l + len;
                if (s[l] == s[r - 1]) {
                    int low = nxt[l], high = prv[r - 1];
                    if (low > high) {
                        dp[l][r] = (dp[l + 1][r - 1] * 2 + 2) % mod;
                    } else if (low == high) {
                        dp[l][r] = (dp[l + 1][r - 1] * 2 + 1) % mod;
                    } else {
                        dp[l][r] = (0LL + dp[l + 1][r - 1] * 2 -
                                    dp[low + 1][high] + mod) %
                                   mod;
                    }
                } else {
                    dp[l][r] = (0LL + dp[l + 1][r] + dp[l][r - 1] -
                                dp[l + 1][r - 1] + mod) %
                               mod;
                }
            }
        }
        return dp[0][n];
    }
};

int main() {
    Solution sol;
    cout << sol.countPalindromicSubsequences("bccb") << endl;
    cout << sol.countPalindromicSubsequences(
                "abcdabcdabcdabcdabcdabcdabcdabcddcbadcbadcbadcbadcbadcbadc"
                "badcba")
         << " 104860361" << endl;
    return 0;
}