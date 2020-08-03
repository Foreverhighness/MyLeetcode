#include <bits/stdc++.h>
using namespace std;
class Solution {
    vector<vector<int>> G;
    vector<char> vis;
    bool dfs(int u) {
        vis[u] = 1;
        for (int v : G[u])
            if (vis[v] == 1 || (!vis[v] && !dfs(v))) return false;
        vis[u] = 2;
        return true;
    }

   public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        G.resize(numCourses);
        vis.resize(numCourses);
        for_each(prerequisites.begin(), prerequisites.end(),
                 [& G = G](vector<int>& vec) { G[vec[1]].push_back(vec[0]); });
        for (int u = 0; u < numCourses; ++u)
            if (!vis[u] && !dfs(u)) return false;
        return true;
    }
};

int main() { return 0; }