#include <bits/stdc++.h>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
   public:
    vector<int> preorderTraversal(TreeNode *root) {
        vector<int> res;
        auto visit = [&](TreeNode *cur) { res.push_back(cur->val); };
        auto cur = root;
        while (cur) {
            auto right_most = cur->left;
            if (right_most) {
                while (right_most->right && right_most->right != cur) {
                    right_most = right_most->right;
                }
                if (right_most->right == nullptr) {
                    visit(cur);
                    right_most->right = cur;
                    cur = cur->left;
                } else {
                    cur = cur->right;
                    right_most->right = nullptr;
                }
            } else {
                visit(cur);
                cur = cur->right;
            }
        }
        return res;
    }
};

int main() { return 0; }