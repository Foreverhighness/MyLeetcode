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
    int res = 0;
    void dfs(TreeNode *cur, int fa, int ga) {
        if (!cur) return;
        if (ga % 2 == 0) res += cur->val;
        dfs(cur->left, cur->val, fa);
        dfs(cur->right, cur->val, fa);
    }

   public:
    int sumEvenGrandparent(TreeNode *root) {
        dfs(root, -1, -1);
        return res;
    }
};

int main() { return 0; }