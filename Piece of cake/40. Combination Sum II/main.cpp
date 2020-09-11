#include <bits/stdc++.h>
using namespace std;
class Solution {
   public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        int n = candidates.size();
        vector<vector<int>> res;
        vector<int> cur;
        sort(candidates.begin(), candidates.end());
        function<void(int, int)> dfs = [&](int idx, int left) {
            if (left == 0) {
                res.emplace_back(cur);
                return;
            }
            for (int i = idx; i < n && candidates[i] <= left; ++i) {
                if (i > idx && candidates[i] == candidates[i - 1]) continue;
                cur.emplace_back(candidates[i]);
                dfs(i + 1, left - candidates[i]);
                cur.pop_back();
            }
        };
        dfs(0, target);
        return res;
    }
};

int main() { return 0; }