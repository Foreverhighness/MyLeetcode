#include <bits/stdc++.h>
using namespace std;
class Solution {
   public:
    int kthSmallest(vector<vector<int>>& mat, int k) {
        int n = mat.size(), lo = 0, hi = 0;
        for (auto&& row: mat) {
            lo += row.front();
            hi += row.back();
        }
        int init = lo, cnt = 0, mi;
        function<void(int, int)> dfs = [&](int row, int cur) {
            if (row == n) {
                ++cnt;
                return;
            }
            cur -= mat[row].front();
            for (int val : mat[row]) {
                if (cur + val > mi || cnt >= k) return;
                dfs(row + 1, cur + val);
            }
        };
        while (lo < hi) {
            mi = (lo + hi) / 2;
            cnt = 0;
            dfs(0, init);
            if (cnt >= k)
                hi = mi;
            else
                lo = mi + 1;
        }
        return lo;
    }
};
class Solution1 {
   public:
    int kthSmallest(vector<vector<int>>& mat, int k) {
        vector<int> res{0};
        for (auto&& line : mat) {
            vector<int> tmp;
            for (int x : res)
                for (int y : line) tmp.push_back(x + y);
            sort(tmp.begin(), tmp.end());
            if ((int)tmp.size() > k) tmp.resize(k);
            res.swap(tmp);
        }
        return res[k - 1];
    }
};
class Solution2 {
   public:
    int kthSmallest(vector<vector<int>>& mat, int k) {
        using P = pair<int, vector<int>>;
        int n = mat.size(), m = mat[0].size(), sum = 0;
        priority_queue<P> pq;
        for (int i = 0; i < n; ++i) sum += mat[i].front();
        pq.push({-sum, vector<int>(n, 0)});
        set<vector<int>> seen;
        while (--k) {
            auto [sum, vec] = pq.top();
            pq.pop();
            for (int i = 0; i < n; ++i) {
                if (vec[i] != m - 1) {
                    auto nxt(vec);
                    ++nxt[i];
                    if (seen.count(nxt) == 0) {
                        seen.insert(nxt);
                        int val = mat[i][vec[i] + 1] - mat[i][vec[i]];
                        pq.push({sum - val, nxt});
                    }
                }
            }
        }
        return -pq.top().first;
    }
};

int main() {
    // vector<vector<int>> vec{{1, 10, 10}, {1, 4, 5}, {2, 3, 6}};
    // vector<vector<int>> vec{{1, 10, 10}, {1, 4, 5}, {2, 3, 6}};
    vector<vector<int>> vec{{1, 2, 7, 8, 10}, {4, 4, 5, 5, 6}, {3, 3, 5, 6, 7}, {2, 4, 7, 9, 9}};
    cout << Solution().kthSmallest(vec, 7) << endl;
    return 0;
}