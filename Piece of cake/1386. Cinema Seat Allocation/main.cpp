#include <bits/stdc++.h>
using namespace std;
class Solution {
   public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        int res = 2 * n, m = reservedSeats.size(), used[10];
        sort(reservedSeats.begin(), reservedSeats.end(),
             [](const vector<int>& lhs, const vector<int>& rhs) {
                 return lhs[0] < rhs[0];
             });
        int i = 0;
        while (i < m) {
            memset(used, false, sizeof(used));
            do {
                used[reservedSeats[i][1]] = true;
                ++i;
            } while (i < m && reservedSeats[i][0] == reservedSeats[i - 1][0]);
            res -= 2;
            for (int j = 2; j <= 6; j += 2) {
                if (!used[j]) {
                    int d = 1;
                    for (d = 1; d < 4; ++d)
                        if (used[d + j]) break;
                    if (d == 4) {
                        ++res;
                        used[d + j - 1] = true;
                    }
                }
            }
        }
        return res;
    }
};

int main() { return 0; }