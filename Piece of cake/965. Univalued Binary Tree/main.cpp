#include <bits/stdc++.h>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution {
public:
    bool isUnivalTree(TreeNode* root) {
        if (root == NULL) return true;
        bool yes = true;
        if (root->left)
            yes &= root->val == root->left->val;
        if (root->right)
            yes &= root->val == root->right->val;
        return yes && isUnivalTree(root->left) && isUnivalTree(root->right);
        
    }
};

int main()
{
    return 0;
}