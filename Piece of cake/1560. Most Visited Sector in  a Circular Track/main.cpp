#include <bits/stdc++.h>
using namespace std;
class Solution {
   public:
    vector<int> mostVisited(int n, vector<int>& rounds) {
        int cnt[n];
        memset(cnt, 0, sizeof(cnt));
        int m = rounds.size();
        for (int j = 1; j < m; ++j) {
            for (int cur = rounds[j - 1] - 1; cur != rounds[j] - 1; cur = (cur + 1) % n) {
                ++cnt[cur];
            }
        }
        ++cnt[rounds.back() - 1];
        int ma = 0;
        for (int i = 0; i < n; ++i) if (cnt[i] > ma)
            ma = cnt[i];

        vector<int> res;
        for (int i = 0; i < n; ++i) if (cnt[i] == ma)
            res.push_back(i);
        return res;
    }
};

int main() { return 0; }