#include <bits/stdc++.h>
using namespace std;
class Solution {
    int solve(const vector<int>& vec, int left, int right) {
        if (left >= right) return -1;
        int mid = (left + right) / 2;
        int leftmost = solve(vec, left, mid);
        if (leftmost != -1)
            return leftmost;
        if (mid == vec[mid])
            return mid;
        return solve(vec, mid + 1, right);
    }
public:
    int findMagicIndex(vector<int>& nums) {
        return solve(nums, 0, nums.size());
    }
};
int main()
{
    return 0;
}