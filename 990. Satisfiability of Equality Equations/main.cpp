#include <bits/stdc++.h>
using namespace std;
class Solution {
    int fa[26];
    int Find(int x) {
        if (x == fa[x]) return x;
        return fa[x] = Find(fa[x]);
    }
    void Union(int x, int y) {
        int fx = Find(x), fy = Find(y);
        if (fx != fy) {
            if (fx < fy) swap(fx, fy);
            fa[fx] = fy;
        }
    }
public:
    bool equationsPossible(vector<string>& equations) {
        for (int i = 0; i < 26; ++i)
            fa[i] = i;
        for (auto&& str: equations) {
            if (str[1] == '=') {
                int a = str[0] - 'a', b = str[3] - 'a';
                Union(a, b);
            }
        }
        for (auto&& str: equations) {
            if (str[1] == '!') {
                int a = str[0] - 'a', b = str[3] - 'a';
                int fa = Find(a), fb = Find(b);
                if (fa == fb)
                    return false;
            }
        }
        return true;
    }
};

int main()
{
    return 0;
}