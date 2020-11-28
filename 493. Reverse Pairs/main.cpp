#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int Merge(vector<int>& nums, vector<int>& tmp, int l, int m, int r) {
        int i = l, j = m, k = l, res = 0;
        while (i < m && j < r) {
            if (nums[i] > 2LL * nums[j]) {
                res += m - i;
                ++j;
            } else {
                ++i;
            }
        }
        i = l, j = m;
        while (i < m && j < r) {
            if (nums[i] > nums[j]) {
                tmp[k++] = nums[j++];
            } else {
                tmp[k++] = nums[i++];
            }
        }
        int n = i < m ? i : j;
        while (k < r) tmp[k++] = nums[n++];
        for (int i = l; i < r; ++i) nums[i] = tmp[i];
        return res;
    }
    int MergeSort(vector<int>& nums, vector<int>& tmp, int l, int r) {
        if (r - l <= 1) return 0;
        int m = (l + r) / 2, res = 0;
        res += MergeSort(nums, tmp, l, m);
        res += MergeSort(nums, tmp, m, r);
        res += Merge(nums, tmp, l, m, r);
        return res;
    }
    int reversePairs(vector<int>& nums) {
        vector<int> tmp(nums.size());
        return MergeSort(nums, tmp, 0, nums.size());
    }
};

int main()
{
    Solution sol;
    int T; cin >> T;
    while (T--) {
        int n; cin >> n;
        vector<int> vec(n);
        for (int i = 0; i != n; ++i)
            cin >> vec[i];
        cout << sol.reversePairs(vec) << endl;
    }
    return 0;
}
/*
Input:
2
5
1 3 2 3 1
5
2 4 3 5 1
Output:
2
3
*/