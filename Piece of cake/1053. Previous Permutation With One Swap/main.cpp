#include <bits/stdc++.h>
using namespace std;
class Solution {
   public:
    vector<int> prevPermOpt1(vector<int>& A) {
        int n = A.size(), mi = 10000;
        priority_queue<pair<int, int>> que;
        for (int i = n - 1; i >= 0; --i) {
            if (A[i] > mi) {
                while (A[i] <= que.top().first) que.pop();
                swap(A[i], A[-que.top().second]);
                break;
            }
            mi = min(mi, A[i]);
            que.push({A[i], -i});
        }
        return A;
    }
};

int main() { return 0; }