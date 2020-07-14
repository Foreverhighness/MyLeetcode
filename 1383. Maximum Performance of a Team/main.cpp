#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maxPerformance(int n, vector<int>& speed, vector<int>& efficiency, int k) {
        const int mod = 1e9 + 7;
        using ll = long long;
        using P = pair<int, int>;
        vector<P> vec;
        for (int i = 0; i != n; ++i) {
            vec.push_back({efficiency[i], speed[i]});
        }
        sort(vec.begin(), vec.end(), [](const P& lhs, const P& rhs) {
            if (lhs.first == rhs.first)
                return lhs.second > rhs.second;
            return lhs.first > rhs.first;
        });
        priority_queue<int> que;
        ll ans = 0, sum = 0;
        for (int i = 0; i != n; ++i) {
            ans = max(ans, vec[i].first * (vec[i].second + sum));
            que.push(-vec[i].second);
            sum += vec[i].second;
            if (que.size() == k) {
                sum += que.top();
                que.pop();
            }
        }
        return ans % mod;
    }
};