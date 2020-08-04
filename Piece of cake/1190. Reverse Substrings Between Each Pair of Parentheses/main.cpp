#include <bits/stdc++.h>
using namespace std;
class Solution {
   public:
    string reverseParentheses(string s) {
        stack<char> sta;
        for (char ch : s) {
            if (ch == ')') {
                queue<char> temp;
                while (!sta.empty()) {
                    char inner = sta.top(); sta.pop();
                    if (inner == '(') break;
                    temp.emplace(inner);
                }
                while (!temp.empty()) {
                    sta.emplace(temp.front()); temp.pop();
                }
            } else {
                sta.emplace(ch);
            }
        }
        string ret;
        while (!sta.empty()) {
            ret.push_back(sta.top()); sta.pop();
        }
        reverse(ret.begin(), ret.end());
        return ret;
    }
};

int main() {
    vector<string> input{
        "(abcd)",                 // dcba
        "(u(love)i)",             // iloveu
        "(ed(et(oc))el)",         // leetcode
        "a(bcdefghijkl(mno)p)q",  // apmnolkjihgfedcbq
    };
    for_each(input.begin(), input.end(), [](const string& str) {
        cout << Solution().reverseParentheses(str) << endl;
    });
    return 0;
}