#include <bits/stdc++.h>
using namespace std;
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
string treeNodeToString(TreeNode* root);
class Solution {
    int res = 0;
    unordered_map<TreeNode*, TreeNode*> fa;
    void dfs(TreeNode* cur) {
        if (cur->left) {
            fa[cur->left] = cur;
            dfs(cur->left);
        }
        if (cur->right) {
            fa[cur->right] = cur;
            dfs(cur->right);
        }
    }
    void build(TreeNode* cur) {
        ++res;
        cur->val = 1;
        if (cur->left && cur->left->val == 0)
            cur->left->val = 2;
        if (cur->right && cur->right->val == 0)
            cur->right->val = 2;
        if (fa[cur] && fa[cur]->val == 0)
            fa[cur]->val = 2;
    }
    void dfs1(TreeNode* cur) {
        // assert(cur != NULL);
        if (cur->left) {
            // assert(fa[cur->left] == cur);
            dfs1(cur->left);
        }
        if (cur->right) {
            // assert(fa[cur->right] == cur);
            dfs1(cur->right);
        }/*
        bool needbuild = false;
        if (cur->left && cur->left->val == 0) {
            needbuild = true;
        }
        if (cur->right && cur->right->val == 0) {
            needbuild = true;
        }
        if (needbuild) {
            ++res;
            cout << "need" << endl;
            build(cur);
        } else */if (cur->val == 0) {/*
            if (fa[cur] == NULL) {
                cout << "cur" << endl;
                build(cur);
            } else {
                cout << "fa" << endl;*/
                build(fa[cur]);/*
            }
        } else if (cur->val == 1) {
            build(cur);*/
        }
    }

   public:
    int minCameraCover(TreeNode* root) {
        fa[root] = new TreeNode(0);
        dfs(root);
        dfs1(root);
        // cout << treeNodeToString(root) << endl;
        // cout << res << endl;
        return res;
    }
};

string treeNodeToString(TreeNode* root) {
    if (root == nullptr) {
        return "[]";
    }

    string output = "";
    queue<TreeNode*> q;
    q.push(root);
    while (!q.empty()) {
        TreeNode* node = q.front();
        q.pop();

        if (node == nullptr) {
            output += "null, ";
            continue;
        }

        output += to_string(node->val) + ", ";
        q.push(node->left);
        q.push(node->right);
    }
    return "[" + output.substr(0, output.length() - 2) + "]";
}
void trimLeftTrailingSpaces(string& input) {
    input.erase(input.begin(), find_if(input.begin(), input.end(),
                                       [](int ch) { return !isspace(ch); }));
}

void trimRightTrailingSpaces(string& input) {
    input.erase(find_if(input.rbegin(), input.rend(),
                        [](int ch) { return !isspace(ch); })
                    .base(),
                input.end());
}
TreeNode* stringToTreeNode(string input) {
    trimLeftTrailingSpaces(input);
    trimRightTrailingSpaces(input);
    input = input.substr(1, input.length() - 2);
    if (!input.size()) {
        return nullptr;
    }

    string item;
    stringstream ss;
    ss.str(input);

    getline(ss, item, ',');
    TreeNode* root = new TreeNode(stoi(item));
    queue<TreeNode*> nodeQueue;
    nodeQueue.push(root);

    while (true) {
        TreeNode* node = nodeQueue.front();
        nodeQueue.pop();

        if (!getline(ss, item, ',')) {
            break;
        }

        trimLeftTrailingSpaces(item);
        if (item != "null") {
            int leftNumber = stoi(item);
            node->left = new TreeNode(leftNumber);
            nodeQueue.push(node->left);
        }

        if (!getline(ss, item, ',')) {
            break;
        }

        trimLeftTrailingSpaces(item);
        if (item != "null") {
            int rightNumber = stoi(item);
            node->right = new TreeNode(rightNumber);
            nodeQueue.push(node->right);
        }
    }
    return root;
}
int main() {
    Solution().minCameraCover(stringToTreeNode("[0,0,null,0,0]"));
    Solution().minCameraCover(stringToTreeNode("[0,0,null,0,null,0,null,null,0]"));
    Solution().minCameraCover(stringToTreeNode("[0,0,0,null,null,0,0]"));
    return 0;
}