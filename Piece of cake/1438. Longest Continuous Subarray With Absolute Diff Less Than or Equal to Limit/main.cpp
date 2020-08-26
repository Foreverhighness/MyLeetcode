#include <bits/stdc++.h>
using namespace std;
class Solution {
   public:
    int longestSubarray(vector<int>& nums, int limit) {
        int n = nums.size(), l = 0, r = 0, res = 1;
        multiset<int> S;
        while (r != n) {
            S.insert(nums[r++]);
            while (*S.rbegin() - *S.begin() > limit) S.erase(S.find(nums[l++]));
            res = max(res, r - l);
        }
        return res;
    }
};
class Solution1 {
    deque<int> mi, ma;
    void push(int x) {
        while (!ma.empty() && ma.back() < x) ma.pop_back();
        ma.push_back(x);

        while (!mi.empty() && mi.back() > x) mi.pop_back();
        mi.push_back(x);
    }
    void pop(int x) {
        if (ma.front() == x) ma.pop_front();
        if (mi.front() == x) mi.pop_front();
    }
    int getMin() { return mi.front(); }
    int getMax() { return ma.front(); }

   public:
    int longestSubarray(vector<int>& nums, int limit) {
        int n = nums.size(), l = 0, r = 0, res = 1;
        while (r != n) {
            push(nums[r++]);
            while (getMax() - getMin() > limit) pop(nums[l++]);
            res = max(res, r - l);
        }
        return res;
    }
};

int main() {
    // vector<int> input{8, 2, 4, 7};
    // cout << Solution().longestSubarray(input, 4) << endl;
    // vector<int> input{4, 2, 2, 2, 4, 4, 2, 2};
    // cout << Solution().longestSubarray(input, 0) << endl;
    // vector<int> input{8, 2, 4, 7};
    // cout << Solution().longestSubarray(input, 4) << endl;
    return 0;
}