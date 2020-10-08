#include <bits/stdc++.h>
using namespace std;
class Solution {
   public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> res;
        int n = nums.size();
        if (n < 4) return res;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < n - 3; ++i) {
            if (i > 0 && nums[i] == nums[i - 1]) continue;
            if (nums[i] + nums[n - 3] + nums[n - 2] + nums[n - 1] < target) continue;
            if (nums[i] + nums[i + 1] + nums[i + 2] + nums[i + 3] > target) break;
            for (int j = i + 1; j < n - 2; ++j) {
                if (j > i + 1 && nums[j] == nums[j - 1]) continue;
                if (nums[i] + nums[j] + nums[n - 2] + nums[n - 1] < target) continue;
                if (nums[i] + nums[j] + nums[j + 1] + nums[i + 2] > target) break;
                int tgt = target - nums[i] - nums[j];
                int l = j + 1, r = n - 1;
                while (l < r) {
                    int cur = nums[l] + nums[r];
                    if (cur == tgt) {
                        res.push_back({nums[i], nums[j], nums[l], nums[r]});
                        do {
                            ++l;
                        } while (l < r && nums[l] == nums[l - 1]);
                        do {
                            --r;
                        } while (l < r && nums[r] == nums[r + 1]);
                    } else if (cur < tgt) {
                        ++l;
                    } else {
                        --r;
                    }
                }
            }
        }
        return res;
    }
};

int main() { return 0; }