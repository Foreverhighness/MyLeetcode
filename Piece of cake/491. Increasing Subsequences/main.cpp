#include <bits/stdc++.h>
using namespace std;
class Solution {
    vector<vector<int>> result;
    vector<int> cur;
    void dfs(vector<int>& nums, vector<int>::size_type idx, int prv) {
        if (idx == nums.size()) {
            if (cur.size() >= 2) {
                result.emplace_back(cur);
            }
            return;
        }
        if (nums[idx] >= prv) {
            cur.push_back(nums[idx]);
            dfs(nums, idx + 1, nums[idx]);
            cur.pop_back();
        }
        if (prv != nums[idx]) {
            dfs(nums, idx + 1, prv);
        }
    }

   public:
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        dfs(nums, 0, INT_MIN);
        return result;
    }
};

int main() { return 0; }