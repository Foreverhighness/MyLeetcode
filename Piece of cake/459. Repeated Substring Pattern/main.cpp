#include <bits/stdc++.h>
using namespace std;
class Solution {
    vector<int> prefix_function(string s) {
        int n = s.length();
        vector<int> pi(n);
        for (int i = 1; i < n; i++) {
            int prv = pi[i - 1];
            while (prv > 0 && s[prv] != s[i]) prv = pi[prv - 1];
            if (s[prv] == s[i]) ++prv;
            pi[i] = prv;
        }
        // for_each(pi.begin(), pi.end(), [](int val) { cout << val << endl; });
        return pi;
    }

   public:
    bool repeatedSubstringPattern(string s) {
        int n = s.length();
        vector<int> fail(prefix_function(s));
        return fail.back() > 0 && n % (n - fail.back()) == 0;
    }
};

int main() {
    cout << boolalpha << Solution().repeatedSubstringPattern("abcdabcd") << endl;
    return 0;
}