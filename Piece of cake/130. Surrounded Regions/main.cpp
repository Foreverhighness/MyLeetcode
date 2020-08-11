#include <bits/stdc++.h>
using namespace std;
class Solution {
    int n, m;
    void dfs(vector<vector<char>>& board, int x, int y) {
        if (0 > x || x >= n || 0 > y || y >= m) return;
        if (board[x][y] != 'O') return;
        board[x][y] = 'A';
        dfs(board, x + 1, y);
        dfs(board, x - 1, y);
        dfs(board, x, y + 1);
        dfs(board, x, y - 1);
    }

   public:
    void solve(vector<vector<char>>& board) {
        n = board.size();
        if (n <= 2) return;
        m = board[0].size();
        if (m <= 2) return;
        for (int x = 0; x < n; ++x) dfs(board, x, 0);
        for (int x = 0; x < n; ++x) dfs(board, x, m - 1);
        for (int y = 0; y < m; ++y) dfs(board, 0, y);
        for (int y = 0; y < m; ++y) dfs(board, n - 1, y);
        for (int x = 0; x < n; ++x)
            for (int y = 0; y < m; ++y)
                if (board[x][y] == 'A')
                    board[x][y] = 'O';
                else if (board[x][y] == 'O')
                    board[x][y] = 'X';
    }
};

class Solution1 {
    constexpr static int maxn = 1e6 + 5;
    constexpr static int dir[4][2] = {
        {1, 0},
        {0, 1},
        {0, -1},
        {-1, 0},
    };
    int fa[maxn];
    int Find(int x) {
        if (x == fa[x]) return x;
        return fa[x] = Find(fa[x]);
    }
    void Union(int x, int y) {
        x = Find(x), y = Find(y);
        if (x != y) {
            if (x < y) swap(x, y);
            fa[x] = y;
        }
    }

   public:
    void solve(vector<vector<char>>& board) {
        int n = board.size();
        if (n == 0) return;
        int m = board[0].size();
        if (m == 0) return;
        iota(fa, fa + n * m, 0);
        for (int i = 0; i < n; ++i) fa[i * m] = fa[i * m + m - 1] = 0;
        for (int j = 0; j < m; ++j) fa[j] = fa[m * (n - 1) + j] = 0;
        for (int i = 1; i < n - 1; ++i) {
            for (int j = 1; j < m - 1; ++j) {
                if (board[i][j] == 'O') {
                    for (int k = 0; k < 4; ++k) {
                        int x = i + dir[k][0], y = j + dir[k][1];
                        if (board[x][y] == 'O') Union(i * m + j, x * m + y);
                    }
                }
            }
        }
        for (int i = 1; i < n - 1; ++i) {
            for (int j = 1; j < m - 1; ++j) {
                if (board[i][j] == 'O' && Find(i * m + j) != 0) {
                    board[i][j] = 'X';
                }
            }
        }
    }
};

int main() { return 0; }