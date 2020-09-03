#include <bits/stdc++.h>
using namespace std;
class Solution {
   public:
    int equalSubstring(string s, string t, int maxCost) {
        int n = s.length(), cost[n];
        for (int i = 0; i < n; ++i) cost[i] = abs(s[i] - t[i]);
        int res = 0, l = 0, r = 0;
        while (r < n) {
            maxCost -= cost[r++];
            while (maxCost < 0) maxCost += cost[l++];
            res = max(res, r - l);
        }
        return res;
    }
};

int main() { return 0; }