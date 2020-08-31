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
    bool isCousins(TreeNode *root, int x, int y) {
        if (!root) return false;
        queue<TreeNode *> que;
        que.emplace(root);
        while (!que.empty()) {
            int sz = que.size();
            TreeNode *fx = nullptr, *fy = nullptr;
            while (sz--) {
                TreeNode *cur = que.front(); que.pop();
                for (TreeNode *nxt : {cur->left, cur->right}) {
                    if (!nxt) continue;
                    if (nxt->val == x) fx = cur;
                    if (nxt->val == y) fy = cur;
                    que.emplace(nxt);
                }
            }
            if (fx || fy) return fx && fy && fx != fy;
        }
        return false;
    }
};

class Solution1 {
    pair<int, int> dfs(TreeNode *cur, int fa, int dep, int x) {
        if (!cur) return {-1, -1};
        if (cur->val == x) return {fa, dep};
        for (auto&& nxt : {cur->left, cur->right})
            if (auto&& res = dfs(nxt, cur->val, dep + 1, x); res.first != -1) return res;
        return {-1, -1};
    }

   public:
    bool isCousins(TreeNode *root, int x, int y) {
        auto fx = std::move(dfs(root, -1, 0, x));
        auto fy = std::move(dfs(root, -1, 0, y));
        if (fx.first != fy.first && fx.second == fy.second) return true;
        return false;
    }
};

int main() { return 0; }