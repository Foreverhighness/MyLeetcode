#include <bits/stdc++.h>
using namespace std;
class Solution {
    constexpr static char *str = " abcdefghijklmnopqrstuvwxyz";
    constexpr static char *b[] = {str, str + 1, str + 1, str + 4, str + 7, str + 10, str + 13, str + 16, str + 20, str + 23, str + 27};
    vector<string> ret;
    string res;
    string_view source;
    int n;
    void dfs(int idx) {
        if (idx == n) {
            ret.emplace_back(res);
            return;
        }
        int i = source[idx] - '0';
        for (char *it = b[i]; it != b[i + 1]; ++it) {
            res.push_back(*it);
            dfs(idx + 1);
            res.pop_back();
        }
    }

   public:
    vector<string> letterCombinations(string digits) {
        n = digits.length();
        if (n == 0) return {};
        res.reserve(n);
        source = digits;
        dfs(0);
        return ret;
    }
};

int main() {
    Solution().letterCombinations("23");
    return 0;
}