#include <bits/stdc++.h>
using namespace std;
class Solution {
 public:
  vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
    constexpr int inf = 0x3f3f3f3f;
    const int m = isWater.size(), n = isWater.at(0).size();
    int d = 1;
    vector<vector<int>> res;
    res.resize(m, vector<int>(n, inf));
    bool* vis = (bool*)malloc(sizeof(bool) * m * n);
    memset(vis, false, sizeof(bool) * m * n);

    function<int(int, int)> dfs = [&](const int x, const int y) {
      if (x < 0 || y < 0 || x >= m || y >= n) {
        return inf;
      }
      if (vis[x * n + y]) {
        return res[x][y];
      }
      if (isWater[x][y]) {
        vis[x * n + y] = true;
        return res[x][y] = 0;
      }
      res[x][y] = min(res[x][y], dfs(x + d, y) + 1);
      res[x][y] = min(res[x][y], dfs(x, y + d) + 1);
      vis[x * n + y] = true;
      return res[x][y];
    };

    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        dfs(i, j);
      }
    }
    memset(vis, false, sizeof(bool) * m * n);
    d = -1;
    for (int i = m - 1; i >= 0; --i) {
      for (int j = n - 1; j >= 0; --j) {
        dfs(i, j);
      }
    }
    return res;
  }
};

int main() {
  Solution sol;
  // vector<vector<int>> vec{{0, 0, 1}, {1, 0, 0}, {0, 0, 0}};
  vector<vector<int>> vec{{1, 1, 0, 1, 1, 1}, {1, 1, 0, 1, 0, 0},
                          {0, 1, 0, 0, 1, 0}, {1, 1, 1, 1, 1, 1},
                          {0, 1, 1, 1, 1, 0}, {1, 1, 1, 0, 0, 0},
                          {1, 1, 0, 1, 1, 1}, {1, 1, 0, 1, 0, 1}};
  int m = vec.size(), n = vec[0].size();
  auto res = sol.highestPeak(vec);
  for (int i = 0; i != m; ++i) {
    for (int j = 0; j != n; ++j) {
      cout << res[i][j] << " \n"[j == n - 1];
    }
  }
  return 0;
}