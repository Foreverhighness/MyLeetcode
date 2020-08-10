#include <bits/stdc++.h>
using namespace std;
class Solution {
   public:
    int maxNonOverlapping(vector<int>& nums, int target) {
        int n = nums.size(), right = -1, res = 0;
        unordered_map<int, int> idx;
        idx[0] = -1;
        for (int i = 0, t = 0; i < n; ++i) {
            t += nums[i];
            if (idx.count(t - target) >= 1 && right <= idx[t - target]) {
                right = i;
                ++res;
            }
            idx[t] = i;
        }
        return res;
    }
};

int main() { return 0; }