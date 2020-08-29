#include <bits/stdc++.h>
using namespace std;
class Solution {
   public:
    int maxScore(string s) {
        int n = s.length(), one[n + 1], res = 0;
        for (int i = 0, t = 0; i < n; ++i) one[i + 1] = t += s[i] - '0';
        for (int i = 1; i < n; ++i) res = max(res, i - one[i] + one[n] - one[i]);
        return res;
    }
};

int main() { return 0; }