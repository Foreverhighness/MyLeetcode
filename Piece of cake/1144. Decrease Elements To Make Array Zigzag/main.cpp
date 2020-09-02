#include <bits/stdc++.h>
using namespace std;
class Solution {
   public:
    int movesToMakeZigzag(vector<int>& nums) {
        int res[2] = {0, 0}, n = nums.size();
        if (n <= 2) return 0;
        for (int i = 0, t; i < n; ++i) {
            if (i == 0)
                t = nums[i + 1];
            else if (i + 1 == n)
                t = nums[i - 1];
            else
                t = min(nums[i - 1], nums[i + 1]);
            if (nums[i] >= t) res[i % 2] += nums[i] - t + 1;
        }
        return min(res[0], res[1]);
    }
};

int main() { return 0; }