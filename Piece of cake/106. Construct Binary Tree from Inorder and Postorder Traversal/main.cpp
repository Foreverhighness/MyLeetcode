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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int m = inorder.size(), n = m;
        if (n == 0) return nullptr;
        TreeNode* root = new TreeNode(postorder[--n]);
        stack<TreeNode*> stk;
        stk.push(root);
        for (int i = n - 1; i >= 0; --i) {
            int val = postorder[i];
            TreeNode* cur = stk.top();
            if (cur->val != inorder[n]) {
                TreeNode* right = new TreeNode(val);
                cur->right = right;
                stk.push(right);
            } else {
                while (!stk.empty() && stk.top()->val == inorder[n]) {
                    cur = stk.top();
                    stk.pop();
                    --n;
                }
                TreeNode* left = new TreeNode(val);
                cur->left = left;
                stk.push(left);
            }
        }
        return root;
    }
};

int main() { return 0; }