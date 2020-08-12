#include <bits/stdc++.h>
using namespace std;
class Solution {
   public:
    vector<vector<int>> queensAttacktheKing(vector<vector<int>>& queens, vector<int>& king) {
        constexpr int n = 8;
        const int x = king[0], y = king[1];
        vector<vector<int>> res;
        unordered_set<int> queen;
        for_each(queens.begin(), queens.end(),
                 [&queen](const vector<int>& vec) {
                     queen.insert(vec[0] * n + vec[1]);
                 });
        for (int dx = -1; dx <= 1; ++dx) {
            for (int dy = -1; dy <= 1; ++dy) {
                if (dx == 0 && dy == 0) continue;
                int nx = x + dx, ny = y + dy;
                while (0 <= nx && nx < n && 0 <= ny && ny < n) {
                    int pos = nx * n + ny;
                    cout << pos;
                    if (queen.count(pos) == 1) {
                        res.push_back({nx, ny});
                        break;
                    }
                    nx += dx, ny += dy;
                }
            }
        }
        return res;
    }
};

int main() {
    vector<vector<int>> q{{0, 1}, {1, 0}, {4, 0}, {0, 4}, {3, 3}, {2, 4}};
    vector<int> k{0, 0};
    auto res = Solution().queensAttacktheKing(q, k);
    for_each(res.begin(), res.end(), [](vector<int>& vec) {
        cout << "[" << vec[0] << ", " << vec[1] << "]\t";
    });
    return 0;
}