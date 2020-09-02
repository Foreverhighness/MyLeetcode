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
    int dfs(TreeNode *cur) {
        if (!cur) return 0;
        return 1 + dfs(cur->left) + dfs(cur->right);
    }

   public:
    bool btreeGameWinningMove(TreeNode *root, int n, int x) {
        if (!root) return false;
        if (root->val != x) return btreeGameWinningMove(root->left, n, x) || btreeGameWinningMove(root->right, n, x);
        int l = dfs(root->left), r = dfs(root->right);
        int half = n / 2;
        return l > half || r > half || (l + r) < half;
    }
};

int main() { return 0; }