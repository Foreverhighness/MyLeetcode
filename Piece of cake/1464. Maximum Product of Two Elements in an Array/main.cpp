#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size(), res = -1e9;
        for (int i = 0; i < n; ++i) for (int j = i + 1; j < n; ++j)
            if ((nums[i] - 1) * (nums[j] - 1) > res) res = (nums[i] - 1) * (nums[j] - 1);
        return res;
    }
};

int main()
{
    return 0;
}