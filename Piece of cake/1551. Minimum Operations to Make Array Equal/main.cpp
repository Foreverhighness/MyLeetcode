#include <bits/stdc++.h>
using namespace std;
class Solution {
   public:
    int minOperations(int n) {
        if (n & 1) {
            n /= 2;
            return n * (n + 1);
        } else {
            n /= 2;
            return n * n;
        }
    }
};

int main() { return 0; }