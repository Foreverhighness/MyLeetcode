#include <bits/stdc++.h>
using namespace std;
class Solution {
   public:
    double new21Game(int N, int K, int W) {
        double dp[K + W], sum = 0;
        int last = K + W - 1;
        for (int i = K; i < K + W; ++i) {
            dp[i] = i <= N ? 1 : 0;
            sum += dp[i];
        } 
        for (int i = K - 1; i >= 0; --i, --last) {
            dp[i] = sum / W;
            sum = dp[i] + sum - dp[last];
        }
        return dp[0];
    }
};

int main() { return 0; }