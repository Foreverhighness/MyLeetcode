#include <bits/stdc++.h>
using namespace std;
class Solution {
    unordered_map<string_view, priority_queue<string_view, vector<string_view>, greater<string_view>>> dic;
    vector<string> res;
    void dfs(string_view cur) {
        auto it = dic.find(cur);
        if (it != dic.end()) {
            auto& pq = it->second;
            while (!pq.empty()) {
                string_view tmp = pq.top();
                pq.pop();
                dfs(tmp);
            }
        }
        res.emplace_back(cur);
    }

   public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        for (auto&& path : tickets) dic[path[0]].emplace(path[1]);
        dfs("JFK");
        reverse(res.begin(), res.end());
        return res;
    }
};

int main() { return 0; }