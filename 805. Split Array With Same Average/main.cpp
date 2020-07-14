#include <bits/stdc++.h>
using namespace std;
bool MeetintheMiddle(vector<int>& A) {
    int n = A.size();
    if (n == 1) return false;
    int sum = accumulate(A.begin(), A.end(), 0), lSum = 0, rSum = 0;
    for (int &a: A)
        a = a * n - sum;
    unordered_set<int> lS, rS;
    for (int i = 0; i != n / 2; ++i) {
        unordered_set<int> tmp;
        tmp.insert(A[i]);
        for (int x: lS)
            tmp.insert(x + A[i]);
        lS.merge(tmp);
        lSum += A[i];
    }
    if (lS.count(0) != 0) return true;

    for (int i = n / 2; i != n; ++i) {
        unordered_set<int> tmp;
        tmp.insert(A[i]);
        for (int x: rS)
            tmp.insert(x + A[i]);
        rS.merge(tmp);
        rSum += A[i];
    }
    if (rS.count(0) != 0) return true;

    for (int x: lS) if (rS.count(-x) != 0 && (x != lSum && -x != rSum))
        return true;

    return false;
}
bool DP(vector<int>& A) {
    int n = A.size();
    if (n == 1) return false;
    int sum = accumulate(A.begin(), A.end(), 0), mi = 0, ma = 0;
    for (int &a: A) {
        a = a * n - sum;
        mi = a < 0 ? mi - a : mi;
        ma = a > 0 ? ma + a : ma;
    }
    int dp[ma + mi + 1], l = mi, r = mi;
    memset(dp, 0, sizeof(dp));
    dp[mi] = 1;
    for (int i = 0; i != n; ++i) {
        if (A[i] > 0) {
            for (int j = r; j >= l; --j) {
                if (dp[j] == 0) continue;
                dp[j + A[i]] += dp[j];
            }
            r += A[i];
        } else {
            for (int j = l; j <= r; ++j) {
                if (dp[j] == 0) continue;
                dp[j + A[i]] += dp[j];
            }
            l += A[i];
        }
    }
    return dp[mi] > 2;
}
int main()
{

    return 0;
}