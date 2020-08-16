#include <bits/stdc++.h>
using namespace std;
class Solution {
    constexpr static int dir[4][2] = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
    int n, m, vis[205][205];
    void dfs(vector<vector<int>>& image, int x, int y, int newColor) {
        vis[x][y] = true;
        for (int i = 0; i < 4; ++i) {
            int nx = x + dir[i][0], ny = y + dir[i][1];
            if (0 <= nx && nx < n && 0 <= ny && ny < m && !vis[nx][ny] && image[nx][ny] == image[x][y])
                dfs(image, nx, ny, newColor);
        }
        image[x][y] = newColor;
    }
   public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        n = image.size();
        if (n == 0) return image;
        m = image[0].size();
        if (m == 0) return image;
        memset(vis, 0, sizeof(vis));
        dfs(image, sr, sc, newColor);
        return image;
    }
};

int main() { return 0; }