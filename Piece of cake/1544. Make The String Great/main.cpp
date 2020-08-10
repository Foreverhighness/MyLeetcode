#include <bits/stdc++.h>
using namespace std;
class Solution {
   public:
    string makeGood(string s) {
        int diff = 'a' - 'A';
        for (;;) {
            int n = s.size();
            bool flag = true;
            for (int i = 0; i <= n - 2; ++i) {
                if (s[i + 1] + diff == s[i] || s[i] + diff == s[i + 1]) {
                    flag = false;
                    s = s.substr(0, i) + s.substr(i + 2, n - i - 1);
                    break;
                }
            }
            if (flag) return s;
        }
    }
};

int main() { return 0; }