#include <bits/stdc++.h>
using namespace std;
// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
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
    ListNode *cur;
    int getlength(ListNode *head) {
        int ret = 0;
        for (; head; ++ret, head = head->next) {
        }
        return ret; 
    }
    TreeNode *build(int L, int R) {
        if (L == R) return nullptr;
        int M = (L + R) / 2;
        TreeNode *left = build(L, M);
        int val = cur->val;
        cur = cur->next;
        TreeNode *right = build(M + 1, R);
        return new TreeNode(val, left, right);
    }

   public:
    TreeNode *sortedListToBST(ListNode *head) {
        cur = head;
        return build(0, getlength(head));
    }
};

int main() { return 0; }