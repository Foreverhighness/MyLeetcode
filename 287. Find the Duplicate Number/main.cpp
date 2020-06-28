#include <bits/stdc++.h>
using namespace std;

int findDuplicate(vector<int>& nums) {
    int n = nums.size() - 1, lo = 1, hi = n;
    while (lo < hi) {
        int mi = (lo + hi) / 2, cnt = 0;
        for (auto&& i: nums) {
            if (i <= mi) ++cnt;
        }
        if (cnt <= mi)  lo = mi + 1;
        else hi = mi;
    }
    return lo;
}

int main()
{
    return 0;
}