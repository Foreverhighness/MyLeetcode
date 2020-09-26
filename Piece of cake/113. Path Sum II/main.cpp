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
   public:
    vector<vector<int>> pathSum(TreeNode *root, int sum) {
        vector<vector<int>> res;
        vector<int> path;
        function<void(TreeNode *)> dfs = [&](TreeNode *cur) {
            if (!cur) return;
            path.emplace_back(cur->val);
            sum -= cur->val;
            if (!cur->left && !cur->right && sum == 0) res.emplace_back(path);
            dfs(cur->left);
            dfs(cur->right);
            sum += cur->val;
            path.pop_back();
        };
        dfs(root);
        return res;
    }
};

int main() { return 0; }