#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int shortestSubarray(vector<int>& A, int K) {
        int n = A.size(), sum[n + 1], res = n + 1;
        deque<int> deq{0};
        sum[0] = 0;
        for (int i = 0, t = 0; i < n; ++i) {
            sum[i + 1] = t += A[i];
            while (!deq.empty() && t - sum[deq.front()] >= K) {
                res = min(res, i + 1 - deq.front());
                deq.pop_front();
            }
            while (!deq.empty() && t < sum[deq.back()]) {
                deq.pop_back();
            }
            deq.push_back(i + 1);
        }
        return res == n + 1 ? -1 : res;
    }
};

int main()
{
    return 0;
}