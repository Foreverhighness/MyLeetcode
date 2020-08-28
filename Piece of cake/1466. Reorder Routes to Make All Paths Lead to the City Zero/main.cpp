#include <bits/stdc++.h>
using namespace std;
class Solution {
    int res = 0;
    vector<vector<pair<int, bool>>> G;
    void dfs(int cur, int fa) {
        for (auto [v, flag] : G[cur]) {
            if (v == fa) continue;
            res += flag;
            dfs(v, cur);
        }
    }

   public:
    int minReorder(int n, vector<vector<int>>& connections) {
        G.resize(n);
        for (auto&& e : connections) {
            G[e[0]].emplace_back(e[1], true);
            G[e[1]].emplace_back(e[0], false);
        }
        dfs(0, -1);
        return res;
    }
};

int main() { return 0; }