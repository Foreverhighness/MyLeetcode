#include <bits/stdc++.h>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
void Preorder(TreeNode* now, vector<int>& ans);

void Inorder(TreeNode* now, vector<int>& ans);

TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
    if (preorder.size() == 0) return nullptr;
    TreeNode* root = new TreeNode(preorder[0]); 
    stack<TreeNode*> sta;
    int idx = 0;
    sta.push(root);
    for (int i = 1; i != preorder.size(); ++i) {
        TreeNode* now = new TreeNode(preorder[i]);
        TreeNode* oldtop = sta.top();

        if (inorder[idx] != oldtop->val) {
            oldtop->left = now;
        } else {
            do {
                oldtop = sta.top();
                ++idx;
                sta.pop();
            } while (!sta.empty() && inorder[idx] == sta.top()->val);
            oldtop->right = now;
        }
        sta.push(now);
    }
    return root;
}
int main()
{
    int i = 0, n = 9;
    vector<int> preorder{3, 9, 8, 5, 4, 10, 20, 15, 7};
    vector<int> inorder{4, 5, 8, 10, 9, 3, 15, 20, 7};
    TreeNode* p = buildTree(preorder, inorder);
    vector<int> tmp;
    Preorder(p, tmp);
    Inorder(p, tmp);
    cout << "[";
    for (; i < n; ++i) {
        cout << tmp[i] << "," << " ]"[i == n - 1];
    }
    cout << "\n[";
    for (; i < 2 * n; ++i) {
        cout << tmp[i] << "," << " ]"[i == 2 * n - 1];
    }
    cout << endl;
    return 0;
}

void Preorder(TreeNode* now, vector<int>& ans) {
    if (now == NULL) return;
    ans.push_back(now->val);
    Preorder(now->left, ans);
    Preorder(now->right, ans);
}
void Inorder(TreeNode* now, vector<int>& ans) {
    if (now == NULL) return;
    Inorder(now->left, ans);
    ans.push_back(now->val);
    Inorder(now->right, ans);
}