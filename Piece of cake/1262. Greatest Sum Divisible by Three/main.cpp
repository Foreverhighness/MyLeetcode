#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    int maxSumDivThree(vector<int>& nums) {
        int dp[2][3], *prv = dp[0], *nxt = dp[1];
        prv[0] = 0;
        prv[1] = prv[2] = INT_MIN;
        for (int val : nums) {
            for (int i = 0; i < 3; ++i) nxt[(i + val) % 3] = max(prv[(i + val) % 3], prv[i] + val);
            swap(prv, nxt);
        }
        return prv[0];
    }
};

class Solution1 {
   public:
    int maxSumDivThree(vector<int>& nums) {
        constexpr int inf = 0x3f3f3f3f;
        int res = 0;
        vector<int> one, two;
        for (int val : nums) {
            int idx = val % 3;
            if (idx == 0)
                res += val;
            else if (idx == 1)
                one.push_back(val);
            else
                two.push_back(val);
        }
        sort(one.begin(), one.end());
        sort(two.begin(), two.end());
        int lone = one.size(), ltwo = two.size();
        while (ltwo > 4) {
            for (int i = 0; i < 3; ++i) res += two[--ltwo];
        }
        while (lone > 4) {
            for (int i = 0; i < 3; ++i) res += one[--lone];
        }
        function<int(int, int)> calc = [&](int lo, int lt) {
            int ret = 0;
            if (lo >= 3) {
                int tlo = lo, tmp = 0;
                for (int i = 0; i < 3; ++i) tmp += one[--tlo];
                ret = max(ret, tmp + calc(tlo, lt));
            }
            if (lt >= 3) {
                int tlt = lt, tmp = 0;
                for (int i = 0; i < 3; ++i) tmp += two[--tlt];
                ret = max(ret, tmp + calc(lo, tlt));
            }
            if (lo >= 1 && lt >= 1) {
                int tmp = one[--lo] + two[--lt];
                ret = max(ret, tmp + calc(lo, lt));
            }
            return ret;
        };
        res += calc(lone, ltwo);
        return res;
    }
};

int main() { return 0; }