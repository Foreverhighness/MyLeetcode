#include <bits/stdc++.h>
using namespace std;
class Solution {
   public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
        sort(points.begin(), points.end(), [](auto&& lhs, auto&& rhs) { return lhs[0] * lhs[0] + lhs[1] * lhs[1] < rhs[0] * rhs[0] + rhs[1] * rhs[1]; });
        vector<vector<int>> res;
        for (int i = 0; i < K; ++i) {
            res.emplace_back(points[i]);
        }
        return res;
    }
};

int main() { return 0; }