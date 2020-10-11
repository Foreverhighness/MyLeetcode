#include <bits/stdc++.h>
using namespace std;
class Solution {
   public:
    bool canPartition(vector<int>& nums) {
        constexpr int maxn = 200 * 100 / 2 + 5;
        bitset<maxn> b(1);
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if (sum & 1) return false;
        for (int x : nums) b |= b << x;
        return b[sum / 2];
    }
};

int main() { return 0; }