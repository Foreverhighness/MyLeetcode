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
    int height(TreeNode *cur) {
        if (!cur) return 0;
        int left = height(cur->left);
        int right = height(cur->right);
        if (left == -1 || right == -1 || abs(left - right) > 1) return -1;
        return max(left, right) + 1;
    }

   public:
    bool isBalanced(TreeNode *root) { return height(root) >= 0; }
};

int main() { return 0; }