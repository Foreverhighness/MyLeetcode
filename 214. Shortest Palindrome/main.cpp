#include <bits/stdc++.h>
using namespace std;
class Solution {
    vector<int> prefix_function(string_view pattern) {
        int n = pattern.length();
        vector<int> pi(n);
        for (int i = 1; i < n; ++i) {
            int prv = pi[i - 1];
            while (prv > 0 && pattern[prv] != pattern[i]) prv = pi[prv - 1];
            if (pattern[prv] == pattern[i]) ++prv;
            pi[i] = prv;
        }
        return pi;
    }

   public:
    string shortestPalindrome(string s) {
        auto nxt(std::move(prefix_function(s)));
        string t(s);
        reverse(t.begin(), t.end());
        int n = s.length(), k = 0;
        for (int i = 0; i < n; ++i) {
            while (k > 0 && t[i] != s[k]) k = nxt[k - 1];
            if (t[i] == s[k]) ++k;
            cout << k << " \n"[i + 1 == n];
        }
        return t.substr(0, n - k) + s;
    }
};

class SolutionManacher2 {
   public:
    string shortestPalindrome(string s) {
        int m = s.length();
        string str;
        str.reserve(2 * m + 3);
        str.append("^#");
        for (char ch : s) {
            str.push_back(ch);
            str.push_back('#');
        }
        str.push_back('$');
        int n = str.size(), radius[n], center = 0, rightMax = 0, res = 0;
        for (int i = 1; i < n - 1; ++i) {
            int iMirror = 2 * center - i;
            radius[i] = i < rightMax ? min(rightMax - i, radius[iMirror]) : 0;
            while (str[i + radius[i] + 1] == str[i - radius[i] - 1]) {
                ++radius[i];
            }
            if (i + radius[i] > rightMax) {
                rightMax = i + radius[i];
                center = i;
            }
            if (i - radius[i] == 1) res = radius[i];
        }
        string t(s.substr(res));
        reverse(t.begin(), t.end());
        return t + s;
    }
};

class SolutionManacher {
   public:
    string shortestPalindrome(string s) {
        string rs(s);
        reverse(rs.begin(), rs.end());
        int m = rs.length();
        string str;
        str.reserve(4 * m + 1);
        str.append("^#");
        for (char ch : rs) {
            str.push_back(ch);
            str.push_back('#');
        }
        for (int i = 0; i < m - 1; ++i) {
            str.push_back('.');
            str.push_back('#');
        }
        str.push_back('$');
        int n = str.size();
        int radius[n], center = 0, rightMax = 0, res = 0;
        for (int i = 1; i < n - 1; ++i) {
            int iMirror = 2 * center - i;
            radius[i] = i < rightMax ? min(rightMax - i, radius[iMirror]) : 0;
            while (str[i + radius[i] + 1] == str[i - radius[i] - 1] || (i - radius[i] - 1 >= 1 && str[i + radius[i] + 1] == '.')) {
                ++radius[i];
            }
            if (i + radius[i] > rightMax) {
                rightMax = i + radius[i];
                center = i;
            }
            if (i > m && i - radius[i] == 1) {
                res = radius[i];
                break;
            }
        }
        return rs.substr(0, res - m) + s;
    }
};

int main() {
    cout << Solution().shortestPalindrome("aacecaaa") << endl;
    // cout << Solution().shortestPalindrome("ababac") << endl;
    return 0;
}