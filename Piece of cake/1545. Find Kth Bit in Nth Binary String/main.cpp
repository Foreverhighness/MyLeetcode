#include <bits/stdc++.h>
using namespace std;
class Solution {
   public:
    char findKthBit(int n, int k) {
        if (n == 1 && k == 1) return '0';
        int half = 1 << (n - 1), len = half << 1;
        if (k == half)
            return '1';
        else if (k < half)
            return findKthBit(n - 1, k);
        else
            return '1' + '0' - findKthBit(n - 1, len - k);
    }
};

int main() { return 0; }