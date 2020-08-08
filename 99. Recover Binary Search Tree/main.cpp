#include <bits/stdc++.h>
using namespace std;
// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right)
        : val(x), left(left), right(right) {}
};

class Solution {
   public:
    void recoverTree(TreeNode *root) {
        TreeNode *cur = root, *prv = nullptr, *x = nullptr, *y = nullptr;
        auto visit = [&]() {
            if (prv && prv->val > cur->val) {
                y = cur;
                if (x == nullptr) x = prv;
            }
            prv = cur;
        };
        while (cur) {
            if (cur->left == nullptr) {
                visit();
                cur = cur->right;
            } else {
                TreeNode *mostRight = cur->left;
                while (mostRight->right && mostRight->right != cur)
                    mostRight = mostRight->right;

                if (mostRight->right) {
                    visit();
                    mostRight->right = nullptr;
                    cur = cur->right;
                } else {
                    mostRight->right = cur;
                    cur = cur->left;
                }
            }
        }
        swap(x->val, y->val);
    }
};

class Solution1 {
   public:
    void recoverTree(TreeNode *root) {
        stack<TreeNode *> sta;
        TreeNode *cur = root, *prv = nullptr, *x = nullptr, *y = nullptr;
        for (;;) {
            while (cur != nullptr) {
                sta.emplace(cur);
                cur = cur->left;
            }
            if (sta.empty()) break;
            cur = sta.top();
            sta.pop();
            // vis(cur)
            if (prv && prv->val > cur->val) {
                y = cur;
                if (!x)
                    x = prv;
                else
                    break;
            }
            prv = cur;
            cur = cur->right;
        }
        swap(x->val, y->val);
    }
};

int main() { return 0; }