#include <bits/stdc++.h>
using namespace std;
vector<int> searchRange(vector<int>& nums, int target) {
    int l = lower_bound(nums.begin(), nums.end(), target) - nums.begin();
    int r = upper_bound(nums.begin(), nums.end(), target) - nums.begin();
    if (l == r) return {-1, -1};
    return {l, r - 1};
}
int main()
{
    
    return 0;
}