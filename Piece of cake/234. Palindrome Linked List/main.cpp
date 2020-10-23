#include <bits/stdc++.h>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
   public:
    bool isPalindrome(ListNode *head) {
        if (!head || !head->next) return true;
        ListNode *p = nullptr, *slow = head, *fast = head->next;
        while (fast && fast->next) {
            fast = fast->next->next;
            ListNode *r = slow->next;
            slow->next = p;
            p = q;
            q = r;
        }
        ListNode *r = slow->next, *l = p;
        if (fast) {
            if (slow->val != r->val) return false;
            r = r->next;
        }
        while (r) {
            if (l->val != r->val) return false;
            l = l->next;
            r = r->next;
        }
        return true;
    }
};

int main() { return 0; }