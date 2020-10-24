#include <bits/stdc++.h>
using namespace std;
class Solution {
   public:
    int videoStitching(vector<vector<int>>& clips, int T) {
        int n = clips.size();
        sort(clips.begin(), clips.end(), [](const auto& lhs, const auto& rhs) { return lhs[0] == rhs[0] ? lhs[1] > rhs[1] : lhs[0] < rhs[0]; });
        int R = 0, res = 0, prv = -1;
        for (auto&& lr : clips) {
            int l = lr[0], r = lr[1];
            if (R < l) return -1;
            if (prv < l) prv = R, ++res;
            R = max(R, r);
            if (R >= T) return res;
        }
        return -1;
    }
};

int main() { return 0; }