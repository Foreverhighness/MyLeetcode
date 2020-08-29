#include <bits/stdc++.h>
using namespace std;
class Solution {
   public:
    vector<int> findDiagonalOrder(vector<vector<int>>& nums) {
        int n = nums.size(), sz = 0;
        map<int, stack<int>> dic;
        for (int i = 0; i < n; ++i) {
            int m = nums[i].size();
            sz += m;
            for (int j = 0; j < m; ++j) dic[i + j].push(nums[i][j]);
        }
        vector<int> res;
        res.reserve(sz);
        for (auto [i, stk] : dic) {
            while (!stk.empty()) {
                res.push_back(stk.top());
                stk.pop();
            }
        }
        return res;
    }
};

int main() { return 0; }