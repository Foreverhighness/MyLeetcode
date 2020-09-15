#include <bits/stdc++.h>
using namespace std;
class Solution {
   public:
    void solveSudoku(vector<vector<char>>& board) {
        constexpr int n = 9;
        constexpr int sqrtn = 3;
        constexpr int mask = (1 << n) - 1;
        int row[n], column[n], block[n];
        memset(row, -1, sizeof(row));
        memset(column, -1, sizeof(column));
        memset(block, -1, sizeof(block));
        vector<pair<int, int>> dot;
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j)
                if (board[i][j] != '.') {
                    int t = 1 << (board[i][j] - '1');
                    row[i] ^= t;
                    column[j] ^= t;
                    block[i / sqrtn * sqrtn + j / sqrtn] ^= t;
                } else {
                    dot.emplace_back(i, j);
                }
        int m = dot.size();
        auto Get = [&](int x, int y) { return row[x] & column[y] & block[x / sqrtn * sqrtn + y / sqrtn] & mask; };
        auto printB = [&board]() {
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < n; ++j) {
                    cout << board[i][j];
                }
                cout<< endl;
            }
            cout << "--------------------------------" << endl;
        };
        auto print = [&](int S) {
            bool first = true;
            cout << "{";
            for (int i = 0; i < n; ++i, S >>= 1) {
                if (S & 1) {
                    if (first) {
                        cout << (i + 1);
                        first = false;
                    } else {
                        cout << ", " << (i + 1);
                    }
                }
            }
            cout << "}" << endl;
        };
        function<bool(int)> dfs = [&](int idx) {
            if (idx == m) return true;
            auto [x, y] = dot[idx];
            // cout << "[" << x << ", " << y << "] -> ";
            int S = Get(x, y);
            // print(S);
            for (int s = S; s; s &= (s - 1)) {
                int lowbit = s & -s, val = __builtin_ctz(lowbit);
                row[x] ^= lowbit;
                column[y] ^= lowbit;
                block[x / sqrtn * sqrtn + y / sqrtn] ^= lowbit;
                board[x][y] = val + '1';

                if (dfs(idx + 1)) return true;

                block[x / sqrtn * sqrtn + y / sqrtn] ^= lowbit;
                column[y] ^= lowbit;
                row[x] ^= lowbit;
            }
            return false;
        };
        dfs(0);
        // for (int i = 0; i < n; ++i) print(row[i]);
        // cout << endl;
        // for (int i = 0; i < n; ++i) print(column[i]);
        // cout << endl;
        // for (int i = 0; i < n; ++i) print(block[i]);
        // cout << endl;
    }
};

int main() {
    vector<vector<char>> input {
        {'5', '3', '.', '.', '7', '.', '.', '.', '.'},
        {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
        {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
        {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
        {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
        {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
        {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
        {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
        {'.', '.', '.', '.', '8', '.', '.', '7', '9'}
    };
    Solution().solveSudoku(input);
    return 0;
}