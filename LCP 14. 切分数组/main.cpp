#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 5;
const int maxv = 1e6 + 5;
const int inf = 0x3f3f3f3f;

int min_prime_factor[maxv];
int prime[maxn];
int f[maxv];

void init() {
    int tot = 0;
    memset(f, inf, sizeof(f));
    for (int i = 2; i != maxv; ++i) {
        if (min_prime_factor[i] == 0) {
            min_prime_factor[i] = i;
            prime[tot++] = i;
        }
        for (int j = 0; j != tot; ++j) {
            if (i > maxv / prime[j]) break;
            min_prime_factor[i * prime[j]] = prime[j];
            if (i % prime[j] == 0) break;
        }
    }
}
int splitArray(vector<int>& nums) {
    init();
    int prv = 0;
    for (int i = 0; i != nums.size(); ++i) {
        int x = nums[i], nxt = prv + 1;
        while (x != 1) {
            int p = min_prime_factor[x];
            nxt = min(nxt, f[p]);
            f[p] = min(f[p], prv + 1);
            while (x % p == 0) x /= p;
        }
        prv = nxt;
    }
    return prv;
}

int main()
{
    int T; cin >> T;
    while (T--) {
        int n; cin >> n;
        vector<int> vec(n);
        for (int i = 0; i != n; ++i)
            cin >> vec[i];
        cout << splitArray(vec) << endl;
    }
    return 0;
}
/*
Input:
2
6
2 3 3 2 3 3
4
2 3 5 7
Output:
2
4
*/