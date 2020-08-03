#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maxSumAfterPartitioning(vector<int>& A, int K) {
        int n = A.size(), dp[n + 1];
        memset(dp, 0, sizeof(dp));
        for (int i = 1; i <= n; ++i) {
            int ma = A[i - 1];
            for (int k = 1; k <= K && i - k >= 0; ++k) {
                ma = max(ma, A[i - k]);
                dp[i] = max(dp[i], dp[i-k] + k * ma);
            }
        }
        return dp[n];
    }
};

int main()
{
    return 0;
}