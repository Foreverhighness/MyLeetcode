#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int constrainedSubsetSum(vector<int>& nums, int k) {
        int res = -1e9;
        deque<int> deq;
        queue<int> que;
        for (int elem : nums) {
            if (!deq.empty()) elem += max(0, deq.front());
            res = max(res, elem);

            if ((int)que.size() == k) {
                int x = que.front(); que.pop();
                if (x == deq.front()) deq.pop_front();
            }
            que.push(elem);
            while (!deq.empty() && deq.back() < elem) deq.pop_back();
            deq.push_back(elem);
        }
        return res;
    }
};

int main()
{
    return 0;
}