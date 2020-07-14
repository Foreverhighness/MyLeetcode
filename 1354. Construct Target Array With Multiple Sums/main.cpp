#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool isPossible(vector<int> target) {
        using P = pair<int, int>;
        int n = target.size(), sum = 0;
        priority_queue<P> que;
        for (int i = 0; i != n; ++i) {
            sum += target[i];
            que.push({target[i], i});
        }
        while (sum > n) {
            auto [prvsum, idx] = que.top(); que.pop();
            int t = sum - prvsum, x = prvsum - t;
            if (x <= 0) return false;
            if (x > t) x = (x % t) + t;
            target[idx] = x;
            sum = x + t;
            // for (int i = 0; i != n; ++i) {
            //     cout << target[i] << ' ';
            // }
            // cout << "sum: " << sum << '\n';
            que.push({x, idx});
        }
        if (sum < n) return false;
        for (int i = 0; i != n; ++i) {
            if (target[i] != 1)
                return false;
        }
        return true;
    }
};
int main()
{
    auto tmp = new Solution();
    cout << tmp->isPossible({9,3,5}) << '\n';       // true
    cout << tmp->isPossible({1,1,1,2}) << '\n';     // false
    cout << tmp->isPossible({8,5}) << '\n';         // true
    cout << tmp->isPossible({9,9,9}) << '\n';       // false
    cout << tmp->isPossible({1,1000000000}) << '\n';// true
    return 0;
}