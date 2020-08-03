#include <bits/stdc++.h>
using namespace std;
class Solution {
    vector<int> G[20005];
    vector<int> mark;
    void dfs(int u) {
        for (int color = 1; color <= 4; ++color) {
            bool used = false;
            for (int v : G[u]) {
                if (mark[v] == color) {
                    used = true;
                    break;
                }
            }
            if (!used) {
                mark[u] = color;
                break;
            }
        }
        for (int v : G[u]) {
            if (mark[v] == 0) {
                dfs(v);
            }
        }
    }

   public:
    vector<int> gardenNoAdj(int N, vector<vector<int>>& paths) {
        mark.resize(N, 0);
        for (auto&& vec : paths) {
            int u = vec[0] - 1, v = vec[1] - 1;
            G[u].push_back(v);
            G[v].push_back(u);
        }
        for (int i = 0; i < N; ++i) {
            if (mark[i] == 0) dfs(i);
        }
        return mark;
    }
};

int main()
{
    return 0;
}