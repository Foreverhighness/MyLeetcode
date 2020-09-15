#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        constexpr int dir[][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        int n = board.size(), m = board[0].size(), k = word.length();
        auto chk = [&](int x, int y) { return 0 <= x && x < n && 0 <= y && y < m; };
        function<bool(int, int)> dfs = [&](int x, int y, int idx) {
            if (idx == t) return true;
            for (auto [dx, dy] : dir){
                int nx = x + dx, ny = y + dy;
                if (chk(nx, ny) && board[nx][ny] == word[idx] && dfs(nx, ny, idx + 1))
                    return true;
            }
            return false;
        };
        for (int x = 0; x < n; ++x) for (int y = 0; y < m; ++y) { 
            if (board[x][y] == word[0] && dfs(x, y, 1))
                return true;
        }
        return false;
    }
};

int main()
{
    return 0;
}