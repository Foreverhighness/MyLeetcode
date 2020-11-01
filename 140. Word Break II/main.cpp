#include <bits/stdc++.h>
using namespace std;
class Solution {
   public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string_view> S;
        unordered_map<int, vector<string>> dp;
        string_view ss{s};
        int n = ss.length();
        dp[n].emplace_back("");
        for (string_view sv : wordDict) S.insert(sv);
        function<void(int)> dfs = [&](int idx) {
            if (dp.count(idx) == 1) return;
            for (int len = 1; idx + len <= n; ++len) {
                string_view sub{ss.substr(idx, len)};
                if (S.count(sub) == 1) {
                    dfs(idx + len);
                    for (string_view sv : dp[idx + len]) dp[idx].emplace_back(sv.empty() ? string{sub} : string{sub} + " " + string{sv});
                }
            }
        };
        dfs(0);
        return dp[0];
    }
};

int main() { return 0; }