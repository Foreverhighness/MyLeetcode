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
    int minDepth(TreeNode *root) {
        if (!root) return 0;
        queue<pair<TreeNode *, int>> que;
        que.emplace(root, 1);
        while (!que.empty()) {
            auto [cur, step] = que.front();
            que.pop();
            if (!cur->left && !cur->right) return step;
            if (cur->left) que.emplace(cur->left, step + 1);
            if (cur->right) que.emplace(cur->right, step + 1);
        }
        return -1;
    }
};

int main() { return 0; }