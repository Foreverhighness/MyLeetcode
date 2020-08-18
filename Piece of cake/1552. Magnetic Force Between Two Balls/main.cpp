#include <bits/stdc++.h>
using namespace std;
class Solution {
   public:
    int maxDistance(vector<int>& position, int m) {
        int n = position.size(), l = 1, r = 1e9;
        sort(position.begin(), position.end());
        auto chk = [&](int mid) {
            int prv = position[0], cnt = 1;
            for (int i = 1; i < n; ++i) {
                if (position[i] - prv >= mid) {
                    prv = position[i];
                    ++cnt;
                    if (cnt >= m) return true;
                }
            }
            return cnt >= m;
        };
        while (r - l > 1) {
            int mid = (l + r) / 2;
            if (chk(mid))
                l = mid;
            else
                r = mid;
        }
        return l;
    }
};

int main() { return 0; }