#include <bits/stdc++.h>
using namespace std;
class Solution {
   public:
    int brokenCalc(int X, int Y) {
        int res = 0;
        while (X < Y) {
            ++res;
            Y = Y & 1 ? Y + 1 : Y / 2;
        }
        return res + X - Y;
    }
};

class Solution1 {
   public:
    int brokenCalc(int X, int Y) {
        if (X >= Y) return X - Y;
        if (Y & 1) return brokenCalc(X, Y + 1);
        return brokenCalc(X, Y / 2);
    }
};

int main() {
    cout << Solution().brokenCalc(3, 1e9 + 7) << endl;         // 45
    cout << Solution().brokenCalc(1e9 + 7, 1e9 + 9) << endl;   // 500000004
    cout << Solution().brokenCalc(998344353, 1e9 + 7) << endl; // 498344351
    return 0;
}