#include <bits/stdc++.h>
using namespace std;
class Solution {
   public:
    int maxCoins(vector<int>& piles) {
        sort(piles.begin(), piles.end());
        int n = piles.size(), m = n / 3, res = 0;
        for (int i = n - 2, j = 0; j != m; ++j, i -= 2) {
            res += piles[i];
        }
        return res;
    }
};

int main() { return 0; }