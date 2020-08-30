#include <bits/stdc++.h>
using namespace std;
class Solution {
   public:
    vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int K) {
        int n = mat.size(), m = mat[0].size();
        vector res(n, vector<int>(m)), sum(n  + 1, vector<int>(m + 1));
        for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j) {
            sum[i + 1][j + 1] = sum[i + 1][j] + sum[i][j + 1] - sum[i][j] + mat[i][j];
        }

        for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j) {
            int lx = max(0, i - K), rx = min(n, i + K + 1), ly = max(0, j - K), ry = min(m, j + K + 1);
            res[i][j] = sum[rx][ry] - sum[lx][ry] - sum[rx][ly] + sum[lx][ly];
        }
        return res;
    }
};

int main()
{
    return 0;
}