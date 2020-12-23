#include <bits/stdc++.h>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
   public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if (!root) return {};
        queue<TreeNode*> que;
        vector<vector<int>> res;
        que.push(root);
        while (!que.empty()) {
            size_t n{que.size()};
            res.emplace_back();
            while (n--) {
                TreeNode* cur{que.front()}; que.pop();
                res.back().emplace_back(cur->val);
                for (TreeNode* nxt : {cur->left, cur->right})
                    if (nxt != nullptr) que.push(nxt);
            }
        }
        for (size_t i{0}; i < res.size(); ++i)
            reverse(res[i].begin(), res[i].end());
        return res;
    }
};

int main() { return 0; }