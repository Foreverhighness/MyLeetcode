#include <bits/stdc++.h>
using namespace std;
class Solution {
   public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        int n = nums.size();
        sort(nums.begin(), nums.end());
        for (int l = 0; l < n - 2 && nums[l] <= 0; ++l) {
            if (l > 0 && nums[l] == nums[l - 1]) continue;
            int m = l + 1, r = n - 1;
            while (m < r) {
                int cur = nums[l] + nums[m] + nums[r];
                if (cur == 0) {
                    res.push_back({nums[l], nums[m], nums[r]});
                    do {
                        ++m;
                    } while (m < r && nums[m] == nums[m - 1]);
                    do {
                        --r;
                    } while (m < r && nums[r] == nums[r + 1]);
                } else if (cur < 0) {
                    ++m;
                } else {
                    --r;
                }
            }
        }
        return res;
    }
};

int main() { return 0; }