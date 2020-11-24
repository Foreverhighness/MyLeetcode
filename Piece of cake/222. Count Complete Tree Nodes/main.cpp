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
    int countNodes(TreeNode* root) {
        int dep = 0;
        TreeNode* cur = root;
        while (cur) {
            cur = cur->left;
            ++dep;
        }
        auto chk = [&](int n) {
            TreeNode* cur = root;
            for (int mask = 1 << (dep - 2); cur != nullptr && mask > 0; mask >>= 1)
                cur = (mask & n) ? cur->right : cur->left;
            return cur != nullptr;
        };
        int hi = 1 << dep, lo = hi >> 1;
        while (hi - lo > 1) {
            int mid = lo + (hi - lo) / 2;
            if (chk(mid)) lo = mid;
            else hi = mid;
        }
        return lo;
    }
};

int main() { return 0; }