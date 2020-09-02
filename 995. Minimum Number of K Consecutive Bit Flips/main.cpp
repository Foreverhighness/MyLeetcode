#include <bits/stdc++.h>
using namespace std;
class Solution {
   public:
    int minKBitFlips(vector<int>& A, int K) {
        int n = A.size(), res = 0, cur = 0;
        queue<int> que;
        for (int i = 0; i < n; ++i) {
            if (!que.empty() && que.front() == i) {
                que.pop();
                cur ^= 1;
            }
            if ((A[i] ^ cur) == 0) {
                if (i + K > n) return -1;
                ++res;
                que.push(i + K);
                cur ^= 1;
            }
        }
        return res;
    }
};

int main() { return 0; }