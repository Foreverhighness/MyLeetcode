#include <bits/stdc++.h>
using namespace std;
class Solution {
   public:
    string removeDuplicates(string s, int k) {
        string res("#");
        stack<int> stk;
        int cnt = 0;
        for (char ch : s) {
            if (ch == res.back()) {
                ++cnt;
            } else {
                stk.emplace(cnt);
                cnt = 1;
            }
            res.push_back(ch);
            if (cnt == k) {
                cnt = stk.top();
                stk.pop();
                res.resize(res.size() - k);
                // cout << res << endl;
            }
        }
        return res.substr(1);
    }
};

int main() { return 0; }