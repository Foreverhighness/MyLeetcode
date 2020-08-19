#include <bits/stdc++.h>
using namespace std;
class Solution {
   public:
    int countSubstrings(string s) {
        string str("^#");
        for_each(s.begin(), s.end(), [&str](char ch) {
            str.push_back(ch);
            str.push_back('#');
        });
        str.push_back('$');
        int n = str.size(), radius[n], res = 0;
        int center = 0, rightMax = 0;
        for (int i = 1; i < n - 1; i++) {
            int iMirror = 2 * center - i;
            radius[i] = i < rightMax ? min(rightMax - i, radius[iMirror]) : 0;
            while (str[i + radius[i] + 1] == str[i - radius[i] - 1]) {
                ++radius[i];
            }
            if (i + radius[i] > rightMax) {
                center = i;
                rightMax = i + radius[i];
            }
            res += (radius[i] + 1) / 2;
        }
        return res;
    }
};

int main() { return 0; }