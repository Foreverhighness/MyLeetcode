#include <bits/stdc++.h>
using namespace std;
class Solution {
    constexpr static int dir[4][2] = {{0, 1}, {-1, 0}, {0, -1}, {1, 0}};

   public:
    bool isRobotBounded(string instructions) {
        int d = 0, x = 0, y = 0;
        for (int i = 0; i != 4; ++i)
            for (char ch : instructions) {
                switch (ch) {
                    case 'G':
                        x += dir[d][0];
                        y += dir[d][1];
                        break;
                    case 'L':
                        d = (d + 1) % 4;
                        break;
                    case 'R':
                        d = (d + 3) % 4;
                        break;
                    default:
                        assert(false);
                }
            }
        return x == 0 && y == 0;
    }
};

int main() { return 0; }