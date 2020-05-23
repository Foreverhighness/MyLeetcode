#include <bits/stdc++.h>
using namespace std;

int superEggDrop(int K, int N) {
    vector<int> dp(K+1);
    int step = 0;
    while (dp[K] < N) {
        for (int k = K; k > 0; --k) {
            dp[k] = dp[k-1] + dp[k] + 1;
        }
        ++step;
    }
    return step;
}
int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        int K, N; cin >> K >> N;
        cout << superEggDrop(K, N) << endl;
    }
    return 0;
}
/*
Input:
3
1 2
2 6
3 14

Output:
2
3
4
*/
