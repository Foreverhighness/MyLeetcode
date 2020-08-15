#include <bits/stdc++.h>
using namespace std;
class Solution {
   public:
    int removeBoxes(vector<int>& boxes) {
        int n = boxes.size(), dp[n + 1][n + 1][n + 1];
        memset(dp, 0, sizeof(dp));
        for (int l = 1; l <= n; ++l) {
            for (int i = 0; i < n - l + 1; ++i) {
                for (int k = 0; k <= i; ++k) {
                    int t = (k + 1) * (k + 1) + dp[l - 1][i + 1][0];
                    for (int j = 1; j < l; ++j)
                        if (boxes[i] == boxes[i + j])
                            t = max(t, dp[j - 1][i + 1][0] + dp[l - j][i + j][k + 1]);
                    dp[l][i][k] = t;
                }
            }
        }
        return dp[n][0][0];
    }
};

class Solution1 {
   public:
    int removeBoxes(vector<int>& boxes) {
        int n = boxes.size(), prv[101], cnt[101], mk[n], mmk = 0;
        vector<int> nxt(n, n);
        memset(prv, -1, sizeof(prv));
        memset(cnt, 0, sizeof(cnt));
        for (int i = 0; i < n; ++i) {
            int b = boxes[i];
            mk[i] = cnt[b];
            mmk = max(mmk, mk[i]);
            ++cnt[b];
            if (prv[b] != -1)
                nxt[prv[b]] = i;
            prv[b] = i;
        }
        int dp[n + 1][n + 1][mmk + 1];
        memset(dp, 0, sizeof(dp));
        for (int l = 1; l <= n; ++l) {
            for (int i = 0; i < n - l + 1; ++i) {
                for (int k = 0; k <= mk[i]; ++k) {
                    int t = (k + 1) * (k + 1) + dp[l - 1][i + 1][0];
                    for (int j = nxt[i]; j < i + l; j = nxt[j]) {
                        t = max(t, dp[j - i - 1][i + 1][0] + dp[l - j + i][j][k + 1]);
                    }
                    dp[l][i][k] = t;
                }
            }
        }
        return dp[n][0][0];
    }
    int t(vector<int> boxes) {
        return removeBoxes(boxes);
    }
};
int main() {
    cout << Solution().t({1, 3, 2, 2, 2, 3, 4, 3, 1}) << endl;
    return 0;
}