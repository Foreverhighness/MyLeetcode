#include <bits/stdc++.h>
using namespace std;
class Solution {
   public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size(), sum = 0;
        for (int i = 0; i < n - k; ++i) sum += cardPoints[i];
        int mi = sum, rangeSum = sum, l = 0, r = n - k;
        while (r != n) {
            sum += cardPoints[r];
            rangeSum += cardPoints[r++] - cardPoints[l++];
            mi = min(mi, sum);
        }
        return sum - mi;
    }
};

int main() { return 0; }