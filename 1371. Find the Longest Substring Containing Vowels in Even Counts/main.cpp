#include <bits/stdc++.h>
using namespace std;
int findTheLongestSubstring(string s) {
    int dp[2][1<<5], *prv = dp[0], *nxt = dp[1];
    char tmp[] = {'a', 'e', 'i', 'o', 'u'}, ma[26] = {};
    for (int i = 0; i != 5; ++i) {
        ma[tmp[i]-'a'] = 1 << i;
    }
    memset(dp, -1, sizeof(dp));
    int res = 0;
    for (auto ch: s) {
        if (prv[0] == -1) prv[0] = 0;
        for (int i = 0; i != 1<<5; ++i) {
            int S = i ^ ma[ch-'a'];
            if (prv[S] == -1) nxt[i] = -1;
            else nxt[i] = prv[S] + 1;
        }
        swap(prv, nxt);
        res = max(res, prv[0]);
    }
    return res;
}
int main()
{
    int T; cin >> T;
    while (T--) {
        string s; cin >> s;
        cout << findTheLongestSubstring(s) << '\n';
    }
    return 0;
}
/*
3
eleetminicoworoep
leetcodeisgreat
bcbcbc
*/