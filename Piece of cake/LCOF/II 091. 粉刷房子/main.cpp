#include <bits/stdc++.h>
using namespace std;
class Solution {
   public:
    int minCost(vector<vector<int>>& costs) {
        int n = costs.size(), m = 3;
        vector<vector<int>> dp(n, vector<int>(m, 0));
        for (int j = 0; j != m; ++j) {
            dp[0][j] = costs[0][j];
        }
        for (int i = 1; i != n; ++i) {
            for (int j = 0; j != m; ++j) {
                dp[i][j] = costs[i][j] +
                           min(dp[i - 1][(j + 1) % m], dp[i - 1][(j + 2) % m]);
            }
        }
        return min({dp[n - 1][0], dp[n - 1][1], dp[n - 1][2]});
    }
};

int main() { return 0; }