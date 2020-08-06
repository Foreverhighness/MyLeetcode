#include <bits/stdc++.h>
using namespace std;
class Solution {
   public:
    int maxSizeSlices(vector<int>& slices) {
        using P = pair<int, int>;
        int n = slices.size(), left[n], right[n];
        iota(left, left + n, -1);
        left[0] = n - 1;
        iota(right, right + n, 1);
        right[n - 1] = 0;
        bool isdeleted[n];
        memset(isdeleted, false, sizeof(isdeleted));
        priority_queue<P> pq;
        for (int i = 0; i < n; ++i) pq.emplace(slices[i], i);
        int res = 0, cnt = n / 3;
        while (cnt) {
            auto [val, idx] = pq.top();
            pq.pop();
            if (isdeleted[idx]) continue;
            isdeleted[left[idx]] = isdeleted[right[idx]] = true;
            --cnt;
            res += val;

            slices[idx] = slices[left[idx]] + slices[right[idx]] - val;
            pq.emplace(slices[idx], idx);

            left[right[right[idx]]] = idx;
            right[left[left[idx]]] = idx;
            left[idx] = left[left[idx]];
            right[idx] = right[right[idx]];
        }
        return res;
    }
};

int main() {
    vector<vector<int>> input{
        {1, 2, 3, 4, 5, 6},
        {8, 9, 8, 6, 1, 1},
        {4, 1, 2, 5, 8, 3, 1, 9, 7},
        {3, 1, 2},
        {10, 1, 1, 2,  1,  10, 3, 10, 2, 8, 4, 10, 8, 8, 2,
         9,  9, 9, 10, 10, 7,  6, 5,  6, 3, 8, 2,  6, 8, 10},
    };
    for_each(input.begin(), input.end(), [](vector<int>& vec) {
        cout << Solution().maxSizeSlices(vec) << endl;
    });
    return 0;
}