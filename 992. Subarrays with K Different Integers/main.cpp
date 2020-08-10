#include <bits/stdc++.h>
using namespace std;
class Solution {
    void print(const map<int, int>& dic) {
        for (auto it = dic.begin(); it != dic.end(); ++it)
            cout << it->first << ":" << it->second << endl;
    }
   public:
    int subarraysWithKDistinct(vector<int>& A, int K) {
        int n = A.size(), l = 0, m = 0, r = 0, res = 0;
        map<int, int> cnt;
        while (r < n) {
            cnt[A[r++]]++;
            if ((int)cnt.size() < K) continue;
            if ((int)cnt.size() == K + 1) {
                cnt.erase(A[m]);
                l = m = m + 1;
            }
            assert((int)cnt.size() == K);
            while (cnt[A[m]] != 1) {
                cnt[A[m]]--;
                ++m;
            }
            res += m - l + 1;
            // cout << "[";
            // for (int i = l; i < m; ++i) {
            //     cout << A[i] << ", ";
            // }
            // cout << "|";
            // for (int i = m; i < r; ++i) {
            //     cout << A[i] << ", ";
            // }
            // cout << "]\n";
            // print(cnt);
        }
        return res;
    }
};

int main() {
    vector<vector<int>> input{
        {1, 2, 1, 2, 3},
        {1, 2, 1, 3, 4},
    };
    vector<int> K{
        2,
        3,
    };
    for (int i = 0; i < (int)input.size(); ++i)
        cout << Solution().subarraysWithKDistinct(input[i], K[i]) << endl;
    return 0;
}
/*
[1,2,1,2,3]
2
[1,2,1,3,4]
3
*/