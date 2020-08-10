#include <bits/stdc++.h>
using namespace std;
class Solution {
   public:
    bool canConvertString(string s, string t, int k) {
        int n = s.length(), m = t.length();
        if (n != m) return false;
        vector<int> cnt(25, k / 26);
        k %= 26;
        for (int i = 0; i < k; ++i) ++cnt[i];
        for (int i = 0; i < n; ++i) {
            int d = (t[i] - s[i] + 26 - 1) % 26;
            if (d != 25) {
                --cnt[d];
                if (cnt[d] < 0) return false;
            }
        }
        return true;
    }
};

int main() { return 0; }