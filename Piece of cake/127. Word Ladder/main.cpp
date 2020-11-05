#include <bits/stdc++.h>
using namespace std;
class Solution {
   public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        int n = wordList.size(), target = 0;
        for (target = 0; target < n; ++target)
            if (wordList[target] == endWord) break;
        if (target == n) return 0;
        auto chk = [](string_view lhs, string_view rhs) {
            bool flag = false;
            for (size_t i = 0; i < lhs.length(); ++i) if (lhs[i] != rhs[i]) {
                if (flag) return false;
                else flag = true;
            }
            return flag;
        };
        vector<int> G[n];
        queue<int> q1, q2;
        bool vis[2][n], *v1 = vis[0], *v2 = vis[1];
        memset(vis, 0, sizeof(vis));
        for (int u = 0; u < n; ++u) {
            for (int v = u + 1; v < n; ++v) if (chk(wordList[u], wordList[v])) {
                G[u].emplace_back(v);
                G[v].emplace_back(u);
            }
            if (chk(wordList[u], beginWord)) {
                q1.push(u);
                v1[u] = true;
            }
        }
        if (v1[target]) return 1;
        q2.push(target);
        v2[target] = true;
        int step = 1;
        while (!q1.empty() && !q2.empty()) {
            ++step;
            bool flag = q1.size() < q2.size();
            queue<int> &q = flag ? q1 : q2;
            v1 = vis[!flag], v2 = vis[flag];
            int sz = q.size();
            while (sz --> 0) {
                int u = q.front(); q.pop();
                for (int v : G[u]) {
                    if (v1[v]) continue;
                    if (v2[v]) return step;
                    q.push(v);
                    v1[v] = true;
                }
            }
        }
        return 0;
    }
};
class Solution0 {
   public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        using P = pair<int, int>;
        constexpr int inf = 0x3f3f3f3f;
        int n = wordList.size(), target = 0;
        for (target = 0; target < n; ++target)
            if (wordList[target] == endWord) break;
        if (target == n) return 0;
        auto chk = [](string_view lhs, string_view rhs) {
            bool flag = false;
            for (size_t i = 0; i < lhs.length(); ++i) if (lhs[i] != rhs[i]) {
                if (flag) return false;
                else flag = true;
            }
            return flag;
        };
        vector<int> G[n];
        for (int u = 0; u < n; ++u) for (int v = u + 1; v < n; ++v) if (chk(wordList[u], wordList[v])) {
            G[u].emplace_back(v);
            G[v].emplace_back(u);
        }
        int dis[n];
        memset(dis, inf, sizeof(dis));
        priority_queue<P> pq;
        for (int u = 0; u < n; ++u) if (chk(beginWord, wordList[u])) {
            dis[u] = 1;
            pq.emplace(-dis[u], u);
        }

        while (!pq.empty()) {
            auto [step, u] = pq.top(); pq.pop();
            if (-step > dis[u]) continue;
            for (auto v : G[u])  if (dis[v] > dis[u] + 1) {
                dis[v] = dis[u] + 1;
                pq.emplace(-dis[v], v);
            }
        }
        return dis[target] == inf ? 0 : dis[target];
    }
};

int main() { return 0; }