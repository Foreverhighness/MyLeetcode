#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int minPushBox(vector<vector<char>>& grid) {
        constexpr int dir[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        int n = grid.size(), m = grid[0].size();
        auto chk = [&](int x, int y) { return 0 <= x && x < n && 0 <= y && y < m; };
        unordered_set<int> seen;
        deque<int> deq;
        int bx, by, px, py, step;
        for (int x = 0; x < n; ++x) for (int y = 0; y < m; ++y)
            if (grid[x][y] == 'S') px = x, py = y;
            else if (grid[x][y] == 'B') bx = x, by = y;
        deq.emplace_back(bx << 23 | by << 18 | px << 13 | py << 8);
        while (!deq.empty()) {
            int cur = deq.front(); deq.pop_front();
            if (seen.count(cur >> 8) != 0) continue;
            seen.insert(cur >> 8);
            bx = cur >> 23 & 0x1F;
            by = cur >> 18 & 0x1F;
            px = cur >> 13 & 0x1F;
            py = cur >>  8 & 0x1F;
            step = cur & 0xFF;
            // cout << bx << by << px << py << step << endl;
            for (auto [dx, dy] : dir) {
                int nx = px + dx, ny = py + dy;
                if (!chk(nx, ny) || grid[nx][ny] == '#') continue;
                if (nx == bx && ny == by) {
                    int nbx = bx + dx, nby = by + dy;
                    if (!chk(nbx, nby) || grid[nbx][nby] == '#') continue;
                    if (grid[nbx][nby] == 'T') return step + 1;
                    deq.emplace_back(nbx << 23 | nby << 18 | nx << 13 | ny << 8 | (step + 1));
                } else {
                    deq.emplace_front(bx << 23 | by << 18 | nx << 13 | ny << 8 | step);
                }
            }
        }
        return -1;
    }
};

int main()
{
    return 0;
}