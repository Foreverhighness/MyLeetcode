#include <bits/stdc++.h>
using namespace std;
class Solution {
   public:
    int rangeBitwiseAnd(int m, int n) {
        while (m < n) n = (n - 1) & n;
        return n;
    }
};

int main() { return 0; }