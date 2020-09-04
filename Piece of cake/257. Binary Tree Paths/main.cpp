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
    vector<string> binaryTreePaths(TreeNode *root) {
        vector<string> res;
        string str;
        function<void(TreeNode *)> dfs = [&](TreeNode *cur) {
            if (cur == nullptr) return;
            string add = "->" + to_string(cur->val);
            str.append(add);
            str += add;
            if (cur->left == nullptr && cur->right == nullptr) res.emplace_back(str.substr(2));
            dfs(cur->left);
            dfs(cur->right);
            str.resize(str.size() - add.size());
        };
        dfs(root);
        return res;
    }
};

int main() { return 0; }