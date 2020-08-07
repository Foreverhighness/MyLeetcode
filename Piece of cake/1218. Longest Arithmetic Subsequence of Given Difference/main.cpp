#include <bits/stdc++.h>
using namespace std;
class Solution {
   public:
    int longestSubsequence(vector<int>& arr, int difference) {
        int n = arr.size(), dp[n], res = 0;
        unordered_map<int, int> mp;
        for (int i = 0; i < n; ++i) {
            dp[i] = 1;
            if (mp.count(arr[i] - difference) == 1)
                dp[i] = dp[mp[arr[i] - difference]] + 1;
            mp[arr[i]] = i;
            res = max(res, dp[i]);
        }
        return res;
    }
};

int main() { return 0; }