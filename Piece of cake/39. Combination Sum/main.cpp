#include <bits/stdc++.h>
using namespace std;
class Solution {
   public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> ans;
        sort(candidates.begin(), candidates.end());
        function<void(vector<int>::iterator, int)> dfs = [&](vector<int>::iterator it, int left) {
            if (left == 0) {
                res.emplace_back(ans);
            } else {
                for (auto i = it; i != candidates.end() && *i <= left; ++i) {
                    ans.emplace_back(*i);
                    dfs(i, left - *i);
                    ans.pop_back();
                }
            }
        };
        dfs(candidates.begin(), target);
        return res;
    }
};

int main() { return 0; }