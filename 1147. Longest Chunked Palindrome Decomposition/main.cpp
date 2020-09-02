#include <bits/stdc++.h>
using namespace std;
class Solution {
    int helper(string_view str) {
        int n = str.length();
        for (int len = 1; len <= n / 2; ++len)
            if (str.substr(0, len) == str.substr(n - len, len)) return helper(str.substr(len, n - len - len)) + 2;
        return min(1, n);
    }

   public:
    int longestDecomposition(string text) { return helper(text); }
};
class Solution1 {
   public:
    int longestDecomposition(string text) {
        string_view str(text);
        int n = str.length(), sz = (n + 1) / 2;
        int dp[sz + 1];
        dp[sz] = 0;
        for (int i = sz - 1; i >= 0; --i) {
            dp[i] = 1;
            for (int len = 1, j = n - i - 1; i + len <= j; ++len, --j) {
                auto l = str.substr(i, len), r = str.substr(j, len);
                // cout << l << " | " << r << endl;
                if (l == r) dp[i] = max(dp[i], dp[i + len] + 2);
            }
        }
        return dp[0];
    }
};

int main() {
    vector input{
        "elvtoelvto", "ghiabcdefhelloadamhelloabcdefghi", "merchant", "antaprezatepzapreanta", "aaa",
    };
    for (auto&& s : input) {
        cout << Solution().longestDecomposition(s) << endl;
    }
    return 0;
}