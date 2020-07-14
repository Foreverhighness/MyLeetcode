#include <algorithm>
using std::swap;
class Solution {
public:
    bool reachingPoints(int sx, int sy, int tx, int ty) {
        while (tx >= sx && ty >= sy) {
            if (sy == ty) return (tx - sx) % sy == 0;
            tx %= ty;
            swap(tx, ty);
            swap(sx, sy);
        }
        return false;
    }
};