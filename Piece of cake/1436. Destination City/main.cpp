#include <bits/stdc++.h>
using namespace std;
class Solution {
   public:
    string destCity(vector<vector<string>>& paths) {
        unordered_map<string_view, int> cnt;
        for (auto&& path : paths) {
            ++cnt[path[0]];
            if (cnt.find(path[1]) == cnt.end()) cnt[path[1]] = 0;
        }
        string res;
        for (auto [s, c] : cnt) {
            if (c == 0) {
                res = s;
                break;
            }
        }
        return res;
    }
};

int main() { return 0; }