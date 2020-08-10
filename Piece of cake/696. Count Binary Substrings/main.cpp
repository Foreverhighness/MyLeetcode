#include <bits/stdc++.h>
using namespace std;
class Solution {
   public:
    int countBinarySubstrings(string s) {
        int res = 0, prvcnt = 0, cnt = 0;
        char prv = '0';
        for_each(s.begin(), s.end(), [&](auto ch){
            if (ch == prv) {
                ++cnt;
            } else {
                prvcnt = cnt;
                cnt = 1;
                prv = ch;
            }
            if (cnt <= prvcnt) ++res;
        });
        return res;
    }
};

int main() { return 0; }