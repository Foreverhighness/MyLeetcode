#include <bits/stdc++.h>
using namespace std;

int minDistance1(vector<int> &houses, int K) {
    int N = houses.size();
    int S[N+1], dp[N + 1];
    memset(dp, 0x3f, sizeof(dp));
    sort(houses.begin(), houses.end());
    S[0] = 0;
    for (int i = 0, t = 0; i < N; ++i) {
        S[i + 1] = (t += houses[i]);
    }
    auto cost = [&](int l, int r) {
        int m = (l + r) / 2, even = S[r] - S[m] + S[l] - S[m], odd = even - houses[m];
        return (l + r) % 2 == 0 ? even : odd;
    };
    dp[0] = 0;
    for (int k = 1; k <= K; ++k) {
        for (int n = N; n >= k; --n) {
            for(int i = k - 1; i < n; ++i) {
                dp[n] = min(dp[n], dp[i] + cost(i, n));
            }
        }
    }
    return dp[N];
}

int cost(int S[], int l, int r, vector<int>& houses) {
    int m = (l + r) / 2, even = S[r] - S[m] + S[l] - S[m], odd = even - houses[m];
    return (l + r) % 2 == 0 ? even : odd;
}
void DC(int* prv, int* nxt, int L, int R, int l, int r, int S[], vector<int>& houses) {
    int M = (L + R) / 2, p = l;
    for (int i = l + 1; i <= r && i < M; ++i) {
        if (prv[i] + cost(S, i, M, houses) < prv[p] + cost(S, p, M, houses))
            p = i;
    }
    nxt[M] = prv[p] + cost(S, p, M, houses);
    if (L < M) DC(prv, nxt, L, M - 1, l, p, S, houses);
    if (M < R) DC(prv, nxt, M + 1, R, p, r, S, houses);
}

int minDistance(vector<int> &houses, int K) {
    int N = houses.size();
    int S[N+1], dp[2][N + 1], *prv = dp[0], *nxt = dp[1];
    memset(dp, 0x3f, sizeof(dp));
    sort(houses.begin(), houses.end());
    S[0] = 0;
    for (int i = 0, t = 0; i < N; ++i) {
        S[i + 1] = (t += houses[i]);
    };
    prv[0] = 0;
    for (int k = 1; k <= K; ++k) {
        DC(prv, nxt, k, N, k - 1, N - 1, S, houses);
        swap(prv, nxt);
    }
    return prv[N];
}

int main()
{
    vector<pair<vector<int>, int>> input{
        {{1, 4,  8, 10, 20}, 3},            // 5
        {{2, 3,  5, 12, 18}, 2},            // 9
        {{7, 4,  6,  1    }, 1},            // 8
        {{3, 6, 14, 10    }, 4},            // 0
    };
    for (auto &&[houses, k] : input)
        cout << minDistance(houses, k) << endl;
    return 0;
}