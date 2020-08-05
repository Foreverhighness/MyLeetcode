#include <bits/stdc++.h>
using namespace std;
class Solution {
   public:
    int minNumberOfSemesters(int n, vector<vector<int>>& dependencies, int k) {
        const int inf = 0x3f3f3f3f;
        int dep[n], dp[1 << n];
        memset(dep, 0, sizeof(dep));
        memset(dp, inf, sizeof(dp));
        for_each(
            dependencies.begin(), dependencies.end(),
            [&dep](vector<int>& vec) { dep[vec[1] - 1] |= 1 << (vec[0] - 1); });
        dp[0] = 0;
        for (int S = 0; S < 1 << n; ++S) {
            if (dp[S] == inf) continue;
            int can = 0;
            for (int i = 0; i < n; ++i) {
                if ((S >> i) & 1) continue;
                if ((S & dep[i]) == dep[i]) can |= 1 << i;
            }
            for (int add = can; add > 0; add = (add - 1) & can) {
                if (__builtin_popcount(add) > k) continue;
                dp[S | add] = min(dp[S | add], dp[S] + 1);
            }
        }
        return dp[(1 << n) - 1];
    }
};

int main() { return 0; }