#include <bits/stdc++.h>
using namespace std;

// Definition for a Node.
class Node {
   public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next) : val(_val), left(_left), right(_right), next(_next) {}
};

class Solution {
   public:
    Node* connect(Node* root) {
        if (!root) return root;
        for (Node* first = root; first->left; first = first->left) {
            for (Node* cur = first;; cur = cur->next) {
                cur->left->next = cur->right;
                if (!cur->next) break;
                cur->right->next = cur->next->left;
            }
        }
        return root;
    }
};

int main() { return 0; }