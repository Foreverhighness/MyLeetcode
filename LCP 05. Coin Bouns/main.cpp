#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 50000 + 5;
const int mod = 1e9 + 7;

int N = 0;
ll sum1[maxn], sum2[maxn];
void add(int idx, int val) {
    for (int i = idx; i <= N; i += i & -i) {
        sum1[i] += val;
        sum2[i] += val * idx;
    }
}
void range_add(int l, int r, int val) {
    add(l, val);
    add(r + 1, -val);
}
ll ask(int idx) {
    ll ret = 0;
    for (int i = idx; i; i -= i & -i) {
        ret += (idx+1) * sum1[i] - sum2[i];
    }
    return ret;
}
ll range_ask(int l, int r) {
    return ask(r) - ask(l - 1);
}

vector<int> son[maxn];
int virtualTree[maxn];
int endPoint[maxn];
void dfs(int idx) {
    virtualTree[idx] = ++N;
    for (int nxt: son[idx]) {
        dfs(nxt);
    }
    endPoint[idx] = N;
}

vector<int> bonus(int n, vector<vector<int>>& leadership, vector<vector<int>>& operations) {
    vector<int> ans;
    for (auto& node: leadership) {
        int a = node[0], b = node[1];
        son[a].push_back(b);
    }
    dfs(1);
    for (auto& op: operations) {
        int Case = op[0];
        if (Case == 1) {
            int start = op[1], val = op[2];
            start = virtualTree[start];
            range_add(start, start, val);
        } else if (Case == 2) {
            int start = op[1], val = op[2];
            int endp = endPoint[start];
            start = virtualTree[start];
            range_add(start, endp, val);
        } else if (Case == 3) {
            int start = op[1];
            int endp = endPoint[start];
            start = virtualTree[start];
            ans.push_back(range_ask(start, endp) % mod);
        } else {
            assert(false);
        }
    }
    return ans;
}

int main()
{
    int T; cin >> T;
    while (T--) {
        int N, Q; cin >> N >> Q;
        vector<vector<int>> leadership(N - 1, vector<int>(2, 0));
        vector<vector<int>> operations(Q);
        for (int i = 0; i != N - 1; ++i) {
            cin >> leadership[i][0] >> leadership[i][1];
        }
        for (auto& op: operations) {
            int t; cin >> t;
            if (t == 3) {
                int a; cin >> a;
                op.resize(2);
                op[0] = t;
                op[1] = a;
            } else {
                int a, b; cin >> a >> b;
                op.resize(3);
                op[0] = t;
                op[1] = a;
                op[2] = b;
            }
        }
        auto ans = bonus(N, leadership, operations);
        for (int i: ans) {
            cout << i << '\n';
        }
    }
    return 0;
}
/*
Input:
1
6 5
1 2
1 6
2 3
2 5
1 4
1 1 500
2 2 50
3 1
2 6 15
3 1
Output:
650
665
*/
vector<int> bonusWithDebug(int n, vector<vector<int>>& leadership, vector<vector<int>>& operations) {
    vector<int> ans;
    // cout << "\nleadership: " << "[";
    for (auto& node: leadership) {
        int a = node[0], b = node[1];
        // cout << "[" << a << ", " << b << "], ";
        son[a].push_back(b);
    }
    // cout << "]\n";
    dfs(1);
    // for (int i = 1; i <= N; ++i) {
    //     int v = virtualTree[i];
    //     cout << i << "-->" << v << '\t' << "ends(" << v << "): " << endPoint[i] << '\n';
    // }
    // cout << "\noperations: " << "[";
    for (auto& op: operations) {
        int Case = op[0];
        if (Case == 1) {
            int start = op[1], val = op[2];
            // cout << "[" << Case << ", " << start << ", " << val << "], ";
            start = virtualTree[start];
            range_add(start, start, val);
        } else if (Case == 2) {
            int start = op[1], val = op[2];
            // cout << "[" << Case << ", " << start << ", " << val << "], ";
            int endp = endPoint[start];
            start = virtualTree[start];
            range_add(start, endp, val);
        } else if (Case == 3) {
            int start = op[1];
            // cout << "[" << Case << ", " << start << "], ";
            int endp = endPoint[start];
            start = virtualTree[start];
            ans.push_back(range_ask(start, endp) % mod);
        } else {
            assert(false);
        }
        // cout << range_ask(1, N) << "  |";
        // for (int i = 1; i <= N; ++i) {
        //     cout << range_ask(i, i) << " \n"[i == N];
        // }
    }
    // cout << "]\n";
    return ans;
}