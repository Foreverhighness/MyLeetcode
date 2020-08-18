#include <bits/stdc++.h>
using namespace std;
class Solution {
    constexpr static int dir[4][2] = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
    int dfs(vector<vector<int>>& grid, int x, int y) {
        int n = grid.size(), m = grid[0].size();
        if (0 <= x && x < n && 0 <= y && y < m && grid[x][y] == 1) {
            grid[x][y] = 0;
            int ret = 1;
            for (int i = 0; i < 4; ++i) {
                int nx = x + dir[i][0], ny = y + dir[i][1];
                ret += dfs(grid, nx, ny);
            }
            return ret;
        }
        return 0;
    }

   public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int res = 0, n = grid.size(), m = grid[0].size();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1) {
                    res = max(res, dfs(grid, i, j));
                }
            }
        }
        return res;
    }
};

int main() { return 0; }