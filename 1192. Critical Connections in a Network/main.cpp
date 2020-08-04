#include <bits/stdc++.h>
using namespace std;
class Solution {
    int time = 0;
    vector<int> dfn, low;
    vector<vector<int>> G;
    vector<vector<int>> res;
    void tarjan(int u, int fa) {
        dfn[u] = low[u] = ++time;
        for (int v : G[u]) {
            if (v == fa) continue;
            if (!dfn[v]) {
                tarjan(v, u);
                low[u] = min(low[u], low[v]);
                if (dfn[u] < low[v]) res.push_back({u, v});
            } else {
                low[u] = min(low[u], dfn[v]);
            }
        }
    }

   public:
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& edges) {
        dfn.resize(n);
        low.resize(n);
        G.resize(n);
        for_each(edges.begin(), edges.end(), [& G = G](vector<int>& e) {
            G[e[0]].push_back(e[1]);
            G[e[1]].push_back(e[0]);
        });
        tarjan(0, -1);
        return res;
    }
};

int main() { return 0; }