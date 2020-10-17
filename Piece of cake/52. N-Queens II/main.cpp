#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int totalNQueens(int n) {
        int res = 0;
        uint mask = (1 << n) - 1;
        function<void(int, int, int, int)> dfs = [&](int x, uint col, uint diag1, uint diag2) {
            if (x == n) {
                ++res;
                return;
            }
            uint S = ~(col | diag1 | diag2) & mask;
            for (uint s = S; s; s = s & (s - 1)) {
                uint lowbit = s & -s;
                dfs(x + 1, col | lowbit, (diag1 | lowbit) << 1, (diag2 | lowbit) >> 1);
            }
        };
        dfs(0, 0, 0, 0);
        return res;
    }
};

int main()
{
    return 0;
}