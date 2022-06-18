#include <bits/stdc++.h>
using namespace std;
// Definition for a Node.
class Node {
   public:
    int val;
    Node* next;

    Node() {}

    Node(int _val) {
        val = _val;
        next = NULL;
    }

    Node(int _val, Node* _next) {
        val = _val;
        next = _next;
    }
};

class Solution {
   public:
    Node* insert(Node* head, int insertVal) {
        Node* node = new Node(insertVal);
        if (head == nullptr) {
            node->next = node;
            return node;
        }
        Node *cur = head, *nxt = head->next;
        while (nxt != head) {
            if (cur->val <= insertVal && insertVal <= nxt->val) {
                break;
            }
            if (cur->val > nxt->val && (insertVal > cur->val || insertVal < nxt->val)) {
                break;
            }
            cur = cur->next;
            nxt = cur->next;
        }
        cur->next = node;
        node->next = nxt;
        return head;
    }
};

int main() { return 0; }