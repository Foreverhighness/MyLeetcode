#include <bits/stdc++.h>
using namespace std;
class Solution {
   public:
    bool lemonadeChange(vector<int>& bills) {
        int five = 0, ten = 0;
        for (int val : bills) {
            if (val == 5)
                ++five;
            else if (val == 10)
                --five, ++ten;
            else if (ten > 0)
                --five, --ten;
            else
                five -= 3;
            if (five < 0) return false;
        }
        return true;
    }
};

int main() { return 0; }