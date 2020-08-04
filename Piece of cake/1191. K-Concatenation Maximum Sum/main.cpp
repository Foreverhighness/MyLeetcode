#include <bits/stdc++.h>
using namespace std;
class Solution {
   public:
    int kConcatenationMaxSum(vector<int>& arr, int k) {
        using ll = long long;
        const int mod = 1e9 + 7;
        int n = arr.size();
        ll sum = 0, maxl = 0, maxr = 0, maxinner = 0;
        for (int i = 0; i < n; ++i) {
            sum += arr[i];
            maxl = max(maxl, sum);
        }
        for (int i = n - 1, t = 0; i >= 0; --i) {
            t += arr[i];
            maxr = max(maxr, (ll)t);
        }
        for (int i = 0, t = 0; i < n; ++i) {
            t += arr[i];
            if (t < 0) t = 0;
            maxinner = max(maxinner, (ll)t);
        }
        if (k == 1) return maxinner;
        return max(maxinner, maxl + maxr + (k - 2) * max(sum, 0LL)) % mod;
    }
};

int main() {
    vector<vector<int>> inputArr{
        {1, 2},
        {1, -2, 1},
        {-1, -2},
    };
    vector<int> inputK{3, 5, 7};
    int n = inputArr.size();
    for (int i = 0; i < n; ++i) {
        cout << Solution().kConcatenationMaxSum(inputArr[i], inputK[i]) << endl;
    }
    return 0;
}