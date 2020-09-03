#include <bits/stdc++.h>
using namespace std;
class Solution {
   public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> res;
        vector<string> cur(n, string(n, '.'));
        uint mask = (1 << n) - 1;
        function<void(int, uint, uint, uint)> dfs = [&](int x, uint col, uint diag1, uint diag2) {
            if (x == n) {
                res.emplace_back(cur);
                return;
            }
            uint S = ~(col | diag1 | diag2) & mask;
            for (uint s = S; s; s = s & (s - 1)) {
                uint lowbit = s & -s;
                int y = __builtin_ctz(lowbit);
                cur[x][y] = 'Q';
                dfs(x + 1, col | lowbit, (diag1 | lowbit) << 1, (diag2 | lowbit) >> 1);
                cur[x][y] = '.';
            }
        };
        dfs(0, 0, 0, 0);
        return res;
    }
};

class Solution1 {
   public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> res;
        vector<string> cur(n, string(n, '.'));
        bool col[n], diag1[2 * n], diag2[2 * n];
        memset(col, false, sizeof(col));
        memset(diag1, false, sizeof(diag1));
        memset(diag2, false, sizeof(diag2));
        function<void(int)> dfs = [&](int x) {
            if (x == n) {
                res.emplace_back(cur);
                return;
            }
            for (int y = 0; y < n; ++y) {
                if (col[y] || diag1[x + y] || diag2[x - y + n]) continue;
                cur[x][y] = 'Q';
                col[y] = true;
                diag1[x + y] = true;
                diag2[x - y + n] = true;
                dfs(x + 1);
                diag2[x - y + n] = false;
                diag1[x + y] = false;
                col[y] = false;
                cur[x][y] = '.';
            }
        };
        dfs(0);
        return res;
    }
};

int main() { return 0; }
