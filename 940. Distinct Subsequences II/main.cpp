#include <bits/stdc++.h>
using namespace std;
class Solution {
   public:
    int distinctSubseqII(string s) {
        constexpr int mod = 1e9 + 7;
        int n = s.size();
        vector<int> dp(n + 1);
        vector<int> last(26, -1);
        dp[0] = 1;
        for (int i = 0; i < n; ++i) {
            int c = s[i] - 'a';
            dp[i + 1] = (2LL * dp[i] - (last[c] == -1 ? 0 : dp[last[c]])) % mod;
            last[c] = i;
        }

        return (dp[n] - 1 + mod) % mod;
    }
};

int main() {
    Solution sol;
    cout << sol.distinctSubseqII("abc") << endl;
    cout << sol.distinctSubseqII("aba") << endl;
    cout << sol.distinctSubseqII("aaa") << endl;
    return 0;
}