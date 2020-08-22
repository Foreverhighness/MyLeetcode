#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        int indegree[n];
        memset(indegree, 0, sizeof(indegree));
        for_each(edges.begin(), edges.end(), [&indegree](auto&& e) { ++indegree[e[1]]; });
        vector<int> res;
        for (int i = 0; i < n; ++i) if (indegree[i] == 0)
            res.push_back(i);
        return res;
    }
};

int main()
{
    return 0;
}