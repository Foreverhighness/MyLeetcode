#include <bits/stdc++.h>
using namespace std;
class Solution {
   public:
    int dieSimulator(int n, vector<int>& rollMax) {
        constexpr int maxr = 15;
        constexpr int maxd = 6;
        constexpr int mod = 1e9 + 7;
        int dp[2][maxd][maxr + 1];
        auto prv = dp[0], nxt = dp[1];
        memset(dp, 0, sizeof(dp));
        for (int d = 0; d < maxd; ++d) prv[d][1] = 1;
        auto up = [](int& a, int b) {
            a += b;
            a = a >= mod ? a - mod : a;
        };
        for (int i = 1; i < n; ++i) {
            memset(nxt, 0, sizeof(dp) / 2);
            for (int d = 0; d < maxd; ++d) {
                for (int r = 1; r <= rollMax[d]; ++r) {
                    for (int nd = 0; nd < maxd; ++nd) {
                        if (nd == d && r + 1 <= rollMax[d])
                            up(nxt[nd][r + 1], prv[d][r]);
                        else if (nd != d)
                            up(nxt[nd][1], prv[d][r]);
                    }
                }
            }
            swap(prv, nxt);
        }
        int res = 0;
        for (int d = 0; d < maxd; ++d)
            for (int r = 1; r <= rollMax[d]; ++r) up(res, prv[d][r]);
        return res;
    }
};

int main() {
    vector<int> ns{2, 2, 3};
    vector<vector<int>> rs{
        {1, 1, 2, 2, 2, 3}, {1, 1, 1, 1, 1, 1}, {1, 1, 1, 2, 2, 3}};
    for (size_t i = 0; i < ns.size(); ++i)
        cout << Solution().dieSimulator(ns[i], rs[i]) << endl;
    return 0;
}