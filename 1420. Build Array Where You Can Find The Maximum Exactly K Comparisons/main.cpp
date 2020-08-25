#include <bits/stdc++.h>
using namespace std;
int dp[100+1][100+1][100+1];
int numOfArraysDP(int n, int m, int k) {
    if (k == 0 || k > m) return 0;
    if (dp[n][m][k]) return dp[n][m][k];
    const int mod = 1e9 + 7;
    
    for (int M = 1; M <= m; ++M)
    for (int N = 1; N <= n; ++N)
        dp[1][M][N] = M;
    
    for (int K = 2; K <= k; ++K) {
        for (int M = k; M <= m; ++M) {
            for (int N = k; N <= n; ++N) {
                dp[K][M][N] = dp[K][M][N-1];
                for (int j = K; j <= M; ++j) {
                    int mul = 1;
                    for (int i = N; i >= K; --i) {
                        dp[K][M][N] = (dp[K][M][N] + 1LL * dp[K-1][M-1][N-1] * mul) % mod;
                        mul = 1LL * mul * j % mod;
                    }
                }
            }
        }
    }
    return dp[k][m][n];
}
int main()
{
    memset(dp, 0, sizeof(dp));
    cout << numOfArraysDP(50, 100, 50) << '\n';
    return 0;
}