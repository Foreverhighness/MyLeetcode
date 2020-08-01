#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maxSatisfied(vector<int>& c, vector<int>& g, int x) {
        int n = c.size(), sum[n+1], sat[n+1];
        sum[0] = sat[0] = 0;
        for (int i = 0, su = 0, sa = 0; i != n; ++i) {
            sum[i + 1] = su += c[i];
            sat[i + 1] = sa += (g[i] == 0 ? c[i] : 0);
        }
        int res = 0;
        for (int start = 0; start + x <= n; ++start) {
            int end = start + x;
            res = max(res, sat[start] + sum[end] - sum[start] + sat[n] - sat[end]);
        }
        return res;
    }
};
int main()
{
    
    return 0;
}