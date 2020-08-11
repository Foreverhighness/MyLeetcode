#include <bits/stdc++.h>
using namespace std;
class Solution {
    int *fa;
    int Find(int x) {
        if (x == fa[x]) return x;
        return fa[x] = Find(fa[x]);
    }
    void Union(int x, int y) {
        x = Find(x), y = Find(y);
        if (x != y) fa[x] = y;
    }
    bool isSimilar(string_view A, string_view B) {
        int diff = 0, n = A.length();
        for (int i = 0; i != n; ++i)
            if (A[i] != B[i] && ++diff > 2) return false;
        return true;
    }

   public:
    int numSimilarGroups(vector<string>& A) {
        sort(A.begin(), A.end());
        A.erase(unique(A.begin(), A.end()), A.end());
        int n = A.size(), w = A[0].length(), _fa[n];
        fa = _fa;
        iota(fa, fa + n, 0);
        if (n < w * w) {
            for (int i = 0; i != n; ++i)
                for (int j = i + 1; j != n; ++j)
                    if (isSimilar(A[i], A[j])) Union(i, j);
        } else {
            unordered_map<string, int> idx;
            int i = 0;
            for (auto&& str: A)
                idx[str] = i++;
            for (int i = 0; i < n; ++i) {
                string& str = A[i];
                for (int j = 0; j < w; ++j)
                    for (int k = j + 1; k < w; ++k)
                        if (str[j] != str[k]) {
                            swap(str[j], str[k]);
                            auto it = idx.find(str);
                            if (it != idx.end())
                                Union(i, it->second);
                            swap(str[j], str[k]);
                        }
            }
        }
        int res = 0;
        for (int i = 0; i < n; ++i)
            if (fa[i] == i) ++res;
        return res;
    }
};

class Solution1 {
    constexpr static int maxn = 2e5 + 5;
    int fa[maxn];
    int Find(int x) {
        if (x == fa[x]) return x;
        return fa[x] = Find(fa[x]);
    }
    void Union(int x, int y) {
        x = Find(x), y = Find(y);
        if (x != y) fa[x] = y;
    }
    bool isSimilar(string_view A, string_view B) {
        int diff = 0, n = A.length();
        for (int i = 0; i != n; ++i)
            if (A[i] != B[i] && ++diff > 2) return false;
        return true;
    }

   public:
    int numSimilarGroups(vector<string>& A) {
        int n = A.size(), w = A[0].length();
        iota(fa, fa + n, 0);
        if (n < w * w) {
            for (int i = 0; i != n; ++i)
                for (int j = i + 1; j != n; ++j)
                    if (isSimilar(A[i], A[j])) Union(i, j);
        } else {
            unordered_map<string, unordered_set<int>> G;
            for (int i = 0; i < n; ++i) {
                string& str = A[i];
                G[str].insert(i);
                for (int j = 0; j < w; ++j)
                    for (int k = j + 1; k < w; ++k)
                        if (str[j] != str[k]) {
                            swap(str[j], str[k]);
                            G[str].insert(i);
                            swap(str[j], str[k]);
                        }
            }
            for (int i = 0; i < n; ++i)
                for (int j : G[A[i]]) Union(i, j);
        }
        int res = 0;
        for (int i = 0; i < n; ++i)
            if (fa[i] == i) ++res;
        return res;
    }
};

int main() { return 0; }