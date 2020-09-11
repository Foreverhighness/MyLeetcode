#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> res;
        vector<int> cur;
        function<void(int, int, int)> dfs = [&](int prv, int cnt, int left) {
            if (cnt == 0) {
                if (left == 0) res.emplace_back(cur);
                return;
            }
            if (prv >= left) return;
            for (int i = prv + 1; i <= 9; ++i) {
                cur.emplace_back(i);
                dfs(i, cnt - 1, left - i);
                cur.pop_back();
            }
        };
        dfs(0, k, n);
        return res;
    }
};

int main() { return 0; }