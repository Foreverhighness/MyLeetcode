#include <bits/stdc++.h>
using namespace std;
class Solution {
    constexpr static int dir[4][2] = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
    constexpr static int maxn = 500 + 5;
    int n, m;
    inline bool chk(int x, int y) { return 0 <= x && x < n && 0 <= y && y < m; }
    bool vis[maxn][maxn];
    bool dfs(vector<vector<char>>& grid, int x, int y, int px, int py) {
        vis[x][y] = 1;
        for (int i = 0; i < 4; ++i) {
            int nx = x + dir[i][0], ny = y + dir[i][1];
            if (!chk(nx, ny)) continue;
            if (nx == px && ny == py) continue;
            if (grid[x][y] != grid[nx][ny]) continue;
            if (vis[nx][ny] == 1 || dfs(grid, nx, ny, x, y)) {
                return true;
            }
        }
        return false;
    }

   public:
    bool containsCycle(vector<vector<char>>& grid) {
        n = grid.size(), m = grid[0].size();
        memset(vis, 0, sizeof(vis));
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (!vis[i][j] && dfs(grid, i, j, -2, -2)) return true;
            }
        }
        return false;
    }
};

int main() { return 0; }