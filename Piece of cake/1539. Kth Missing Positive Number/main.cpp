#include <bits/stdc++.h>
using namespace std;
class Solution {
   public:
    int findKthPositive(vector<int>& arr, int k) {
        if (k < arr[0]) return k;
        k -= arr[0] - 1;
        int n = arr.size();
        for (int i = 0; i < n - 1; ++i) {
            if (k < arr[i + 1] - arr[i]) return arr[i] + k;
            k -= arr[i + 1] - arr[i] - 1;
        }

        return arr[n - 1] + k;
    }
};

int main() { return 0; }