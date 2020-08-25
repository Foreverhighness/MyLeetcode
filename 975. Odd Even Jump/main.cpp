#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    int oddEvenJumps(vector<int>& A) {
        int n = A.size(), oddNext[n], evenNxt[n], res = 1;
        vector<int> idx(n);
        iota(idx.begin(), idx.end(), 0);
        auto make = [&](int* nxt) {
            stack<int> stk;
            for (int i : idx) {
                while (!stk.empty() && stk.top() < i) {
                    nxt[stk.top()] = i;
                    stk.pop();
                }
                stk.push(i);
            }
            while (!stk.empty()) {
                nxt[stk.top()] = n;
                stk.pop();
            }
        };
        stable_sort(idx.begin(), idx.end(), [&A](int lhs, int rhs) { return A[lhs] < A[rhs]; });
        make(oddNext);
        stable_sort(idx.begin(), idx.end(), [&A](int lhs, int rhs) { return A[lhs] > A[rhs]; });
        make(evenNxt);

        bool can[n + 1][2];
        memset(can, false, sizeof(can));
        can[n - 1][0] = can[n - 1][1] = true;
        for (int i = n - 2; i >= 0; --i) {
            can[i][0] = can[oddNext[i]][1];
            can[i][1] = can[evenNxt[i]][0];
            if (can[i][0]) ++res;
        }
        return res;
    }
};

class Solution1 {
   public:
    int oddEvenJumps(vector<int>& A) {
        using P = pair<int, int>;
        int n = A.size(), oddNext[n], evenNxt[n], res = 1;
        memset(oddNext, -1, sizeof(oddNext));
        memset(evenNxt, -1, sizeof(evenNxt));
        set<P> tmp{{INT_MIN, n}, {INT_MAX, n}};
        for (int i = n - 1; i >= 0; --i) {
            auto it = tmp.lower_bound({A[i], i});
            oddNext[i] = it->second;
            if (A[i] != it->first) {
                --it;
                evenNxt[i] = it->second;
            } else {
                evenNxt[i] = it->second;
                tmp.erase(it);
            }
            tmp.insert({A[i], i});
        }

        bool can[n + 1][2];
        memset(can, false, sizeof(can));
        can[n - 1][0] = can[n - 1][1] = true;
        for (int i = n - 2; i >= 0; --i) {
            can[i][0] = can[oddNext[i]][1];
            can[i][1] = can[evenNxt[i]][0];
            if (can[i][0]) ++res;
        }
        // for (int i = 0; i < n; ++i) {
        //     cout << can[i][0] << " \n"[i + 1 == n];
        // }
        // for (int i = 0; i < n; ++i) {
        //     cout << can[i][1] << " \n"[i + 1 == n];
        // }
        return res;
    }
};

int main() {
    vector<int> input{10, 13, 12, 14, 15};
    cout << Solution().oddEvenJumps(input) << endl;
    return 0;
}