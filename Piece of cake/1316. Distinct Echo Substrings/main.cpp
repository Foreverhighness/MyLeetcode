#include <bits/stdc++.h>
using namespace std;
class Solution {
   public:
    int distinctEchoSubstrings(string text) {
        int n = text.length();
        string_view str(text);
        auto chk = [](string_view s) { return s.substr(0, s.length() / 2) == s.substr(s.length() / 2, s.length() / 2); };
        unordered_set<string_view> S;
        for (int len = 2; len <= n; len += 2) for (int start = 0; start + len <= n; ++start) {
            string_view sub = str.substr(start, len);
            if (chk(sub)) S.insert(sub);
        }
        return S.size();
    }
};

int main()
{
    return 0;
}