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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> res;
        queue<TreeNode *> que;
        if (root) que.emplace(root);
        while (!que.empty()) {
            int sz = que.size();
            vector<int> row;
            while (sz--) {
                TreeNode *cur = que.front(); que.pop();
                row.emplace_back(cur->val);
                if (cur->left) que.emplace(cur->left);
                if (cur->right) que.emplace(cur->right);
            }
            res.emplace_back(row);
        }
        reverse(res.begin(), res.end());
        return res;
    }
};

int main()
{
    return 0;
}