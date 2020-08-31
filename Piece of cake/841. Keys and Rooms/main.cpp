#include <bits/stdc++.h>
using namespace std;
class Solution {
   public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();
        bool vis[n];
        memset(vis, 0, sizeof vis);
        queue<int> que;
        que.push(0);
        while (!que.empty()) {
            int cur = que.front();
            que.pop();
            if (vis[cur]) continue;
            vis[cur] = true;
            for (int nxt : rooms[cur]) que.push(nxt);
        }
        for (int i = 0; i < n; ++i)
            if (!vis[i]) return false;
        return true;
    }
};

int main() { return 0; }