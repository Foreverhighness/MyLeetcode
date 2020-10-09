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
    bool hasCycle(ListNode *head) {
        auto slow = head, fast = head ? head->next : nullptr;
        while (fast) {
            if (slow == fast) return true;
            slow = slow->next;
            fast = fast->next;
            fast = fast ? fast->next : nullptr;
        }
        return false;
    }
};
class Solution1 {
   public:
    bool hasCycle(ListNode *head) {
        if (!head || !head->next) return false;
        auto slow = head, fast = head->next;
        while (slow != fast) {
            if (!fast || !fast->next) return false;
            slow = slow->next;
            fast = fast->next->next;
        }
        return true;
    }
};

int main() { return 0; }