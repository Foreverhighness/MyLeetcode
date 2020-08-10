#include <bits/stdc++.h>
using namespace std;
class Solution {
   public:
    int minInsertions(string s) {
        long long res = 0, cnt = 0;
        int n = s.size();
        s.push_back('#');
        for (int i = 0; i < n; ++i) {
            char ch = s[i];
            if (ch == '(') {
                cnt += 1;
            } else {
                if (cnt == 0) {
                    res += 1;
                    cnt += 1;
                }
                if (s[i + 1] == ')') {
                    cnt -= 1;
                    ++i;
                } else {
                    res += 1;
                    cnt -= 1;
                }
            }
        }
        return res + 2 * cnt;
    }
};

int main() { return 0; }