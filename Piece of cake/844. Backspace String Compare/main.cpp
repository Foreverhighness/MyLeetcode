#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool backspaceCompare(string S, string T) {
        auto make = [](string_view s) {
            string ret;
            for (char ch : s)
                if (ch != '#') ret.push_back(ch);
                else if (!ret.empty()) ret.pop_back();
            return ret;
        };
        return make(S) == make(T);
    }
};

int main()
{
    return 0;
}