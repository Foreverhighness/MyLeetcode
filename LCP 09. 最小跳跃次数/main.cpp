#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> P;
const int maxn = 1e6 + 5;


int minJump(vector<int>& jump) {
    int N = jump.size(), far = 1;
    bool vis[N];
    memset(vis, 0, sizeof(vis));
    queue<P> que;
    que.push({0, 0});
    vis[0] = true;
    while (!que.empty()) {
        P p = que.front(); que.pop();
        int now = p.first, dep = p.second + 1;
        int nxt = now + jump[now];
        if (nxt >= N) return dep;
        if (!vis[nxt]) que.push({nxt, dep});
        vis[nxt] = true;
        for (int i = 1; i < now; ++i) if (!vis[now]) {
            que.push({now, dep});
            vis[now] = true;
        }
        // far = max(far, now+1);
    }
    return -1;
}
int main()
{
    vector<int> vec{2, 5, 1, 1, 1, 1};
    cout << minJump(vec) << endl;
    return 0;
}
int minJumpAC(vector<int>& jump) {
    int N = jump.size();
    bool vis[N];
    memset(vis, 0, sizeof(vis));
    priority_queue<P> que;
    que.push({0, 0});
    vis[0] = true;
    while (!que.empty()) {
        P p = que.top(); que.pop();
        int dep = 1-p.first, now = p.second;
        int nxt = now + jump[now];
        if (nxt >= N) return dep;
        if (!vis[nxt]) que.push({-dep, nxt});
        vis[nxt] = true;
        while (--now > 0 && !vis[now]) {
            que.push({-dep, now});
            vis[now] = true;
        }
    }
    return -1;
}