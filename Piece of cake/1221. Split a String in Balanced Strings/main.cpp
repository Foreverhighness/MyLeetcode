#include <bits/stdc++.h>
using namespace std;
class Solution {
   public:
    int balancedStringSplit(string s) {
        int cnt = 0, res = 0;
        for (char ch : s) {
            if (ch == 'R')
                ++cnt;
            else
                --cnt;
            if (cnt == 0) ++res;
        }
        return res;
    }
};

int main() { return 0; }