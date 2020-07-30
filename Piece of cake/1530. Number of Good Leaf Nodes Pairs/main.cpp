#include <bits/stdc++.h>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
    int res = 0, d = 0;
    vector<int> dfs(TreeNode* cur) {
        if (!cur->left && !cur->right) return {1};
        vector<int> left, right;
        if (cur->left)
            left = dfs(cur->left);
        if (cur->right)
            right = dfs(cur->right);
        for (int l: left) for (int r: right)
                if (l + r <= d)
                    ++res;
        vector<int> ret;
        for (int l: left) if (l + 1 < d)
            ret.emplace_back(l + 1);
        for (int r: right) if (r + 1 < d)
            ret.emplace_back(r + 1);
        return ret;
    }
public:
    int countPairs(TreeNode* root, int dis) {
        d = dis;
        dfs(root);
        return res;
    }
};
int main()
{
    
    return 0;
}