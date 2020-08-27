#include <bits/stdc++.h>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
    vector<int> res;
    bool vis[505] = {};
    unordered_map<TreeNode*, TreeNode*> fa;
    void getfa(TreeNode* cur, TreeNode* father) {
        if (!cur) return;
        fa[cur] = father;
        getfa(cur->left, cur);
        getfa(cur->right, cur);
    }
    void dfs(TreeNode* cur, int dis) {
        if (!cur || vis[cur->val]) return;
        vis[cur->val] = true;
        if (dis == 0) {
            res.emplace_back(cur->val);
            return ;
        }
        dfs(cur->left, dis - 1);
        dfs(cur->right, dis - 1);
        dfs(fa[cur], dis - 1);
    }


public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int K) {
        getfa(root, nullptr);
        dfs(target, K);
        return res;
    }
};

int main()
{
    return 0;
}