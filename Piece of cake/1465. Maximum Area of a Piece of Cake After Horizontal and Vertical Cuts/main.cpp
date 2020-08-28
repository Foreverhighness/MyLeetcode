#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maxArea(int h, int w, vector<int>& horizontalCuts, vector<int>& verticalCuts) {
        constexpr int mod = 1e9 + 7;
        horizontalCuts.push_back(0);
        horizontalCuts.push_back(h);
        verticalCuts.push_back(0);
        verticalCuts.push_back(w);
        sort(verticalCuts.begin(), verticalCuts.end());
        sort(horizontalCuts.begin(), horizontalCuts.end());
        int n = horizontalCuts.size(), m = verticalCuts.size(), mh = -1, mv = -1;
        for (int i = 1; i < n; ++i) mh = max(mh, horizontalCuts[i] - horizontalCuts[i - 1]);
        for (int i = 1; i < m; ++i) mv = max(mv, verticalCuts[i] - verticalCuts[i - 1]);
        return 1LL * mh * mv % mod;
    }
};

int main()
{
    return 0;
}