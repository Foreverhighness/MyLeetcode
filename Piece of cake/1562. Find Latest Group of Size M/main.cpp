#include <bits/stdc++.h>
using namespace std;
class Solution {
   public:
    int findLatestStep(vector<int>& arr, int m) {
        int n = arr.size();
        if (n == m) return n;
        set<int> zeros{0, n + 1};
        for (int i = n - 1; i >= 0; --i) {
            int idx = arr[i];
            auto l = zeros.lower_bound(idx);
            auto r = l--;
            int left = *l, right = *r;
            if (idx - left - 1 == m || right - idx - 1 == m) return i;
            zeros.insert(idx);
        }
        return -1;
    }
};

int main() { return 0; }