#include <bits/stdc++.h>
using namespace std;
class Solution {
   public:
    vector<int> addToArrayForm(vector<int>& A, int K) {
        reverse(A.begin(), A.end());
        int idx = 0, carry = 0;
        while (K || carry) {
            if (idx == A.size()) A.push_back(0);
            int t = A[idx] + K % 10 + carry;
            if (t < 10) {
                carry = 0;
            } else {
                carry = 1;
                t -= 10;
            }
            A[idx] = t;
            ++idx;
            K /= 10;
        }
        reverse(A.begin(), A.end());
        return A;
    }
};

int main() { return 0; }