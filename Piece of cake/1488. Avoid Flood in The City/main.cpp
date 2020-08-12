#include <bits/stdc++.h>
using namespace std;
class Solution {
   public:
    vector<int> avoidFlood(vector<int>& rains) {
        int n = rains.size();
        vector<int> res(n, -1);
        unordered_map<int, int> prv;
        set<int> can;
        for (int i = 0; i < n; ++i) {
            int cur = rains[i];
            if (cur == 0) {
                can.insert(i);
                res[i] = 1;
            } else {
                if (prv.count(cur) == 1) {
                    auto it = can.upper_bound(prv[cur]);
                    if (it == can.end()) return {};
                    res[*it] = cur;
                    can.erase(it);
                }
                prv[cur] = i;
            }
        }
        return res;
    }
};

int main() { return 0; }