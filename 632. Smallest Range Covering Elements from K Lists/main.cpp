#include <bits/stdc++.h>
using namespace std;
class Solution {
   public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        int K = nums.size(), l = -1e5, r = 1e5;
        vector<int> nums_size(K);
        vector<int> idx(K, 0);              // 每个列表中大于等于 l 的最小的 idx
        int a = -1e6, b = -1e6;             // 维护动态区间 [a, b]
        for (int k = 0; k < K; k++) {
            nums_size[k] = nums[k].size();
            b = max(b, nums[k][0]);
        }
        for (;;) {
            int nextA = 100000;
            for (int k = 0; k < K; k++) {
                int i = idx[k], sz = nums_size[k];
                while (nums[k][i] == a) {
                    if (++i == sz) return {l, r};
                    b = max(b, nums[k][i]); // b 向后移动，保证覆盖所有数组
                }
                nextA = min(nextA, nums[k][i]);
                idx[k] = i;
            }
            a = nextA;
            if (b - a < r - l) {
                r = b;
                l = a;
            }
        }
    }
};

int main() {
    Solution S;
    vector<vector<int>> in{
        {4, 10, 15, 24, 26}, {0, 9, 12, 20}, {5, 18, 22, 30}};
    vector<int> ans = S.smallestRange(in);
    for_each(ans.begin(), ans.end(),
             [](const int elem) { cout << ' ' << elem; });
    cout << '\n';
    return 0;
}