#include <bits/stdc++.h>
using namespace std;
class Solution {
    static constexpr int factorial[] = {1, 1, 2, 6, 24, 120, 720, 5040, 40320};

   public:
    string getPermutation(int n, int k) {
        vector<int> nums(n);
        iota(nums.begin(), nums.end(), 1);
        string ret;
        --k;
        for (int i = n - 1; i >= 0; --i) {
            auto it = nums.begin() + k / factorial[i];
            ret += ('0' + *it);
            nums.erase(it);
            k %= factorial[i];
        }
        return ret;
    }
};

int main() { return 0; }