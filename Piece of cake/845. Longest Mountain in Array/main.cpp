#include <bits/stdc++.h>
using namespace std;
class Solution {
   public:
    int longestMountain(vector<int>& A) {
        int n = A.size(), res = 0, start = n;
        for (int i = 1; i < n; ++i) {
            if (A[i - 1] == A[i]) {
                start = n;
            } else if (A[i - 1] < A[i]) {
                if (i == 1 || A[i - 2] >= A[i - 1]) start = i - 1;
            } else {
                res = max(res, i - start + 1);
            }
        }
        return res;
    }
};

int main() { return 0; }