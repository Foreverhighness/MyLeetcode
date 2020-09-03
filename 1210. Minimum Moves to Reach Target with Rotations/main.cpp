#include <bits/stdc++.h>
using namespace std;
class Solution {
   public:
    int minimumMoves(vector<vector<int>>& grid) {
        constexpr int inf = 0x3f3f3f3f;
        int n = grid.size();
        if (grid[n - 1][n - 1] || grid[n - 1][n - 2]) return -1;
        int dp[n][n][2];
        memset(dp, 0x3f, sizeof(dp));
        dp[n - 1][n - 2][0] = 0;
        for (int x = n - 1; x >= 0; --x) for (int y = n - 1; y >= 0; --y) {
            if (grid[x][y] == 1) continue;
            for (int d : {0, 1}) {
                int hx = x + d, hy = y + !d;
                // 首先验证该状态是否合法
                if (hx < n && hy < n && !grid[hx][hy]) {
                    dp[x][y][d] = min(dp[x][y][d], 1 + min(dp[x + 1][y][d], dp[x][y + 1][d]));
                    // 转圈时不能碰头
                    if (x + 1 < n && y + 1 < n && grid[x + 1][y + 1] == 0 && grid[x + !d][y + d] == 0) {
                        dp[x][y][d] = min(dp[x][y][d], 2 + min(dp[x + 1][y][!d], dp[x][y + 1][!d]));
                    }
                }
            }
        }
        return dp[0][0][0] == inf ? -1 : dp[0][0][0];
    }
};

class Solution1 {
   public:
    int minimumMoves(vector<vector<int>>& grid) {
        constexpr int dir[][2] = {{0, 1}, {1, 0} /*, {0, -1}, {-1, 0}*/};
        int n = grid.size();
        uint target = (n - 1) << 10 | (n - 2) << 2;
        auto chk = [&](int x, int y) { return 0 <= x && x < n && 0 <= y && y < n; };
        unordered_set<uint> seen;
        queue<uint> que;
        que.emplace(0);
        int step = 0;
        while (!que.empty()) {
            int sz = que.size();
            while (sz--) {
                uint state = que.front();
                que.pop();
                if (state == target) return step;
                if (seen.find(state) != seen.end()) continue;
                seen.insert(state);
                int x = state >> 10 & 0xFF;
                int y = state >> 2 & 0xFF;
                int d = state & 0x3;
                for (auto [dx, dy] : dir) {
                    int nx = x + dx, ny = y + dy, tx = nx + dir[d][0], ty = ny + dir[d][1];
                    if (chk(nx, ny) && grid[nx][ny] == 0 && chk(tx, ty) && grid[tx][ty] == 0) {
                        que.emplace(nx << 10 | ny << 2 | d);
                    }
                }
                for (int dd : {1}) {
                    int nd = (d + dd) % 2;
                    int tx = x + dir[nd][0], ty = y + dir[nd][1], bx = tx + dir[d][0], by = ty + dir[d][1];
                    if (chk(tx, ty) && grid[tx][ty] == 0 && grid[bx][by] == 0) {
                        que.emplace(x << 10 | y << 2 | nd);
                    }
                }
            }
            ++step;
        }
        return -1;
    }
};

int main() { return 0; }