#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n = nums.size(), l[n], r[n];
        for (int i = 0, t = 0; i < n; ++i) {
            if (nums[i]) {
                ++t;
            } else {
                t = 0;
            }
            l[i] = t;
        }
        for (int i = n - 1, t = 0; i >= 0; --i) {
            if (nums[i]) {
                ++t;
            } else {
                t = 0;
            }
            r[i] = t;
        }
        int res = 0;
        for (int i = 0; i < n; ++i) {
            int len = 0;
            if (i - 1 >= 0) len += l[i - 1];
            if (i + 1 < n)  len += r[i + 1];
            res = max(res, len);
        }
        return res;
    }
};

int main()
{
    return 0;
}