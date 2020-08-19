#include <bits/stdc++.h>
using namespace std;
class Solution {
    int n, m;
    inline bool isLegal(int x, int y) { return 0 <= x && x < n && 0 <= y && y < m; }
    void dfs(vector<vector<char>>& board, int x, int y) {
        if (board[x][y] == 'M') {
            board[x][y] = 'X';
            return;
        }
        if (board[x][y] != 'E') return;
        int cnt = 0;
        for (int dx = -1; dx <= 1; ++dx) {
            for (int dy = -1; dy <= 1; ++dy) {
                int nx = x + dx, ny = y + dy;
                if (isLegal(nx, ny) && board[nx][ny] == 'M') ++cnt;
            }
        }
        if (cnt != 0) {
            board[x][y] = '0' + cnt;
            return;
        }
        board[x][y] = 'B';
        for (int dx = -1; dx <= 1; ++dx) {
            for (int dy = -1; dy <= 1; ++dy) {
                int nx = x + dx, ny = y + dy;
                if (isLegal(nx, ny)) dfs(board, nx, ny);
            }
        }
    }

   public:
    vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click) {
        n = board.size(), m = board[0].size();
        dfs(board, click[0], click[1]);
        return board;
    }
};

int main() { return 0; }
