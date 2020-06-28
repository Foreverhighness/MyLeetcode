#include <bits/stdc++.h>
using namespace std;
const int inf = 0x3f3f3f3f;
const int dir[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
typedef pair<int, int> P;
int dp[1 << 16][16]; // 表示完成S现在在i的最小距离。
int dist[80][80]; // 表示编号i到j的最小距离。
bool vis[105][105];
vector<P> M;
vector<P> O;
P S, T;
int N, K;
void init() {
    memset(dp, inf, sizeof(dp));
    memset(dist, inf, sizeof(dist));
    for (int i = 0; i < 70; ++i)
        dist[i][i] = 0;
}
void build(vector<string>& maze) {
    int H = maze.size(), W = maze[0].size();
    for (int x = 0; x != H; ++x) for (int y = 0; y != W; ++y) {
        if (maze[x][y] == '.' || maze[x][y] == '#') {
        } else if (maze[x][y] == 'O') {
            O.push_back({x, y});
        } else if (maze[x][y] == 'M') {
            M.push_back({x, y});
        } else if (maze[x][y] == 'S') {
            S.first = x, S.second = y;
        } else if (maze[x][y] == 'T') {
            T.first = x, T.second = y;
        } else {
            assert(false);
        }
    }
    N = M.size();
    M.push_back(S);
    K = M.size() + O.size();
    O.push_back(T);
    queue<pair<P, int>> que;
    for (int i = 0; i != O.size(); ++i) {
        int Oi = M.size() + i;
        memset(vis, 0, sizeof(vis));
        while (!que.empty()) que.pop();
        que.push({O[i], 0});
        while (!que.empty()) {
            auto p = que.front(); que.pop();
            P pos = p.first;
            int x = pos.first, y = pos.second, step = p.second;
            if (x < 0 || y < 0 || x >= H || y >= W || vis[x][y] || maze[x][y] == '#') continue;
            if (maze[x][y] == 'M' || maze[x][y] == 'S') {
                int Mi = find(M.begin(), M.end(), pos) - M.begin();
                dist[Mi][Oi] = dist[Oi][Mi] = min(dist[Oi][Mi], step);
            }
            vis[x][y] = true;
            for (int k = 0; k != 4; ++k) {
                int nx = x + dir[k][0], ny = y + dir[k][1];
                que.push({{nx, ny}, step + 1});
            }
        }
    }
    for (int i = 0; i <= N; ++i) {
        for (int j = i + 1; j <= N; ++j) {
            int res = inf;
            for (int k = N + 1; k < K; ++k) {
                res = min(res, dist[i][k] + dist[k][j]);
            }
            dist[i][j] = dist[j][i] = res;
        }
    }
    for (int i = 0; i <= K; ++i) {
        for (int j = 0; j <= K; ++j) {
            cout << (dist[i][j] == inf ? -1 : dist[i][j]) << '\t';
        }
        cout << '\n';
    }
}
int minimalSteps(vector<string>& maze) {
    init();
    build(maze);
    if (N == 0) return dist[0][K] == inf ? -1: dist[0][K];
    auto log = [](int x) {
        int ret = 0;
        if (x & 0xFF00) ret += 8, x >>= 8;
        if (x & 0x00F0) ret += 4, x >>= 4;
        if (x & 0x000C) ret += 2, x >>= 2;
        if (x & 0x0002) ret += 1, x >>= 1;
        return ret;
    };
    auto lowbit = [](int x) { return x & -x; };
    int _S = 1 << N;
    for (int s = 1; s != _S; ++s) {
        int x = s;
        if (x == lowbit(x)) {
            dp[s][log(x)] = dist[log(x)][N];
            continue;
        }
        while (x) {
            int lx = lowbit(x), i = log(lx), y = x ^ lx;
            while (y) {
                int ly = lowbit(y), j = log(ly);
                // cout << "think with dp(" << s << "," << i << ")=" << (dp[s][i] == inf ? -1: dp[s][i]) << " and ";
                // cout << "dp(" << s << "^" << lx << "=" << (s^lx) << "," << j << ")=" << (dp[s^lx][i] == inf ? -1: dp[s^lx][i]);
                // cout << "+" << dist[j][i] << '\n';
                dp[s][i] = min(dp[s][i], dp[s^lx][j] + dist[j][i]);
                dp[s][j] = min(dp[s][j], dp[s^ly][i] + dist[i][j]);
                y = y ^ ly; 
            }
            x = x ^ lx;
        }
    }
    for (int s = 1; s != _S; ++s) {
        cout << "S: " << s << '\t';
        for (int i = 0; i != N; ++i) {
            cout << (dp[s][i] == inf ? -1: dp[s][i]) << ' ';
        }
        cout << '\n';
    }
    int res = inf;
    --_S;
    for (int i = 0; i < N; ++i) {
        res = min(res, dp[_S][i] + dist[i][K]);
    }
    if (res == inf) res = -1;
    return res;
}
int main()
{
    // vector<string> maze{"S#O", "M..", "M.T"}; // 16
    vector<string> maze{"S#O", "M.#", "M.T"}; // -1
    // vector<string> maze{"S#O", "M.T", "M.."}; // 17
    cout << minimalSteps(maze) << endl;
    return 0;
}