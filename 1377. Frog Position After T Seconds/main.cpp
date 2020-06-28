#include <bits/stdc++.h>
using namespace std;
const int maxn = 100 + 5;
const double eps = 1e-6;
double dp[maxn];
bool vis[maxn];
int tgt;
vector<int> G[maxn];
void dfs(int now, int cnt, double p) {
    if (cnt == 0) {
        dp[now] += p;
        return ;
    }
    vis[now] = true;
    vector<int> tmp;
    for (auto&& v: G[now]) if (!vis[v]) {
        tmp.push_back(v);
    }
    for (auto &&v : tmp) {
        dfs(v, cnt - 1, p / tmp.size());
    }
    if (!tmp.empty()) {
        dp[now] = 0;
    } else {
        dp[now] += p;
    }
}

double frogPosition(int n, vector<vector<int>>& edges, int t, int target) {
    memset(dp, 0, sizeof(dp));
    memset(vis, 0, sizeof(vis));
    for (auto&& edge: edges) {
        G[edge[0]].push_back(edge[1]);
        G[edge[1]].push_back(edge[0]);
    }
    dp[1] = 1.0;
    tgt = target;
    dfs(1, t, 1.0);
    return dp[target];
}

int main()
{
    int n = 7;
    vector<vector<int>> edges{{1,2},{1,3},{1,7},{2,4},{2,6},{3,5}};
    // int t = 2, target = 4; // 0.16666666666666666
    int t = 1, target = 7; // 0.33333333333333333
    // int t = 20, target = 6;// 0.16666666666666666
    cout << frogPosition(n, edges, t, target) << endl;;
    return 0;
}
/*
n = 7, edges = {{1,2},{1,3},{1,7},{2,4},{2,6},{3,5}}, t = 2, target = 4  // 0.16666666666666666 
n = 7, edges = {{1,2},{1,3},{1,7},{2,4},{2,6},{3,5}}, t = 1, target = 7  // 0.33333333333333333
n = 7, edges = {{1,2},{1,3},{1,7},{2,4},{2,6},{3,5}}, t = 20, target = 6 // 0.16666666666666666



n = 7, edges = [[1,2],[1,3],[1,7],[2,4],[2,6],[3,5]], t = 2, target = 4  // 0.16666666666666666 
n = 7, edges = [[1,2],[1,3],[1,7],[2,4],[2,6],[3,5]], t = 1, target = 7  // 0.33333333333333333
n = 7, edges = [[1,2],[1,3],[1,7],[2,4],[2,6],[3,5]], t = 20, target = 6 // 0.16666666666666666
*/