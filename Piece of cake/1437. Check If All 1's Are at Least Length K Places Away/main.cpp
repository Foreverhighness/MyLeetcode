#include <bits/stdc++.h>
using namespace std;
class Solution {
   public:
    bool kLengthApart(vector<int>& nums, int k) {
        int prv = -1e5, n = nums.size();
        for (int i = 0; i < n; ++i) {
            if (nums[i] == 1) {
                if (i - prv <= k) return false;
                prv = i;
            }
        }
        return true;
    }
};

int main() { return 0; }