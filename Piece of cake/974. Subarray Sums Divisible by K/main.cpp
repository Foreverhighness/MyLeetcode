#include <bits/stdc++.h>
using namespace std;
class Solution {
   public:
    int subarraysDivByK(vector<int>& A, int K) {
        const acc = K * 100000;
        int n = A.size(), cnt[K], sum = 0, res = 0;
        memset(cnt, 0, sizeof(cnt));
        cnt[0] = 1;
        for (int val : A) {
            sum = (sum + val + acc) % K;
            res += cnt[sum];
            ++cnt[sum];
        }
        return res;
    }
};

int main() { return 0; }