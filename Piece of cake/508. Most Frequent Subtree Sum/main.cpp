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
    vector<int> findFrequentTreeSum(TreeNode *root) {
        unordered_map<int, int> cnt;
        vector<int> ans;
        int max_cnt = -1;
        function<int(TreeNode *)> dfs = [&](TreeNode *root) -> int {
            int sum = root->val;
            if (root->left) sum += dfs(root->left);
            if (root->right) sum += dfs(root->right);
            max_cnt = max(max_cnt, ++cnt[sum]);
            return sum;
        };
        dfs(root);
        for (auto [k, v] : cnt)
            if (v == max_cnt) ans.push_back(k);
        return ans;
    }
};

int main() { return 0; }