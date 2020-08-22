#include <bits/stdc++.h>
using namespace std;
class Solution {
   public:
    int minOperations(vector<int>& nums) {
        int res = 0, n = nums.size();
        while (true) {
            bool allZero = true;
            for (int i = 0; i < n; ++i) {
                res = (nums[i] & 1) ? res + 1: res;
                nums[i] /= 2;
                allZero = (allZero && nums[i] != 0) ? false : allZero;
            }
            if (allZero) break;
            ++res;
        }
        return res;
    }
};

int main() {
    vector<vector<int>> in{{1, 5}, {2, 2}, {4, 2, 5}, {3, 2, 2, 4}, {2, 4, 8, 16}};
    for (auto&& vec : in) cout << Solution().minOperations(vec) << endl;
    return 0;
}