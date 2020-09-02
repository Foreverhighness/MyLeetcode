#include <bits/stdc++.h>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class FindElements {
    unordered_set<int> S;
    void dfs(TreeNode *cur, int val) {
        if (!cur) return;
        cur->val = val;
        S.insert(val);
        dfs(cur->left, 2 * val + 1);
        dfs(cur->right, 2 * val + 2);
    }

   public:
    FindElements(TreeNode *root) { dfs(root, 0); }

    bool find(int target) { return S.count(target) != 0; }
};

/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements* obj = new FindElements(root);
 * bool param_1 = obj->find(target);
 */

int main() { return 0; }