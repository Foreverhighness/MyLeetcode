#include <bits/stdc++.h>
using namespace std;
class Solution {
   public:
    int orangesRotting(vector<vector<int>>& grid) {
        using P = pair<int, int>;
        constexpr int dir[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        int n = grid.size(), m = grid[0].size(), fresh = 0, res = 0;
        queue<P> que;
        for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j)
            if (grid[i][j] == 1) 
                ++fresh;
            else if (grid[i][j] == 2) 
                que.emplace(i, j);
        
        auto chk = [&](int x, int y) { return 0 <= x && x < n && 0 <= y && y < m; };
        while (fresh && !que.empty()) {
            ++res;
            int sz = que.size();
            while (sz--) {
                auto [x, y] = que.front(); que.pop();
                for (auto [dx, dy] : dir) {
                    int nx = x + dx, ny = y + dy;
                    if (chk(nx, ny) && grid[nx][ny] == 1) {
                        grid[nx][ny] = 2;
                        --fresh;
                        que.emplace(nx, ny);
                    }
                }
            }
        }
        return fresh == 0 ? res : -1;
    }
};

int main() { return 0; }