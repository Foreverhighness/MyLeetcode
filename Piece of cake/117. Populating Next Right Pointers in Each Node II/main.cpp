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
        for (Node* first = root; first;) {
            Node *prv = nullptr, *cur = first;
            first = nullptr;
            for (; cur; cur = cur->next) {
                for (Node* nxt : {cur->left, cur->right}) {
                    if (!nxt) continue;
                    if (prv)
                        prv->next = nxt;
                    else
                        first = nxt;
                    prv = nxt;
                }
            }
        }
        return root;
    }
};

int main() { return 0; }