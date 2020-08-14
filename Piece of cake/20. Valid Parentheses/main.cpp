#include <bits/stdc++.h>
using namespace std;
class Solution {
   public:
    bool isValid(string s) {
        stack<char> sta;
        for (char ch : s) {
            switch (ch) {
            case '(': case '[': case '{':
                ch += 1 + (ch >= '[');
                sta.push(ch);
                break;
            case ')': case ']': case '}':
                if (sta.empty() || sta.top() != ch) return false;
                sta.pop();
                break;
            }
        }
        return sta.empty();
    }
};

int main() { return 0; }