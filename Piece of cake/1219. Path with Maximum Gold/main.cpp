#include <bits/stdc++.h>
using namespace std;
class Solution {
    constexpr static int dir[4][2] = {
        {0, 1},
        {1, 0},
        {0, -1},
        {-1, 0},
    };
    vector<vector<int>> G;
    int res = 0, sum = 0;
    void dfs(int x, int y) {
        if (G[x][y] == 0) {
            res = max(res, sum);
            return;
        }
        int t = G[x][y];
        G[x][y] = 0;
        sum += t;
        for (int i = 0; i < 4; ++i) {
            int nx = x + dir[i][0], ny = y + dir[i][1];
            dfs(nx, ny);
        }
        sum -= t;
        G[x][y] = t;
    }

   public:
    int getMaximumGold(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        G.resize(n + 2, vector<int>(m + 2));
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < m; ++j) G[i + 1][j + 1] = grid[i][j];
        for (int i = 1; i <= n; ++i)
            for (int j = 1; j <= m; ++j)
                if (G[i][j] != 0) dfs(i, j);
        return res;
    }
};

int main() {
    vector<vector<int>> i1{{0, 6, 0}, {5, 8, 7}, {0, 9, 0}},
        i2{{1, 0, 7}, {2, 0, 6}, {3, 4, 5}, {0, 3, 0}, {9, 0, 20}};
    cout << Solution().getMaximumGold(i1) << endl;
    cout << Solution().getMaximumGold(i2) << endl;
    return 0;
}