#include <bits/stdc++.h>
using namespace std;
class Solution {
   public:
    int largestPerimeter(vector<int>& A) {
        int n = A.size();
        sort(A.begin(), A.end());
        for (int i = n - 3; i >= 0; --i) {
            if (A[i] + A[i + 1] > A[i + 2]) return A[i] + A[i + 1] + A[i + 2];
        }
        return 0;
    }
};

int main() { return 0; }