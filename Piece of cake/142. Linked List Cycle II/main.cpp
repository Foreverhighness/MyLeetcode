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
    ListNode *detectCycle(ListNode *head) {
        auto slow = head, fast = head;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast) {
                while (head != slow) {
                    head = head->next;
                    slow = slow->next;
                }
                return head;
            }
        }
        return nullptr;
    }
};

class Solution2 {
   public:
    ListNode *detectCycle(ListNode *head) {
        if (!head || !head->next) return nullptr;
        auto slow = head, fast = head->next;
        while (slow != fast) {
            if (!fast || !fast->next) return nullptr;
            slow = slow->next;
            fast = fast->next->next;
        }

        int cnt = 0;
        do {
            ++cnt;
            slow = slow->next;
            fast = fast->next->next;
        } while (slow != fast);

        slow = fast = head;
        while (cnt--) fast = fast->next;
        while (slow != fast) {
            slow = slow->next;
            fast = fast->next;
        }
        return slow;
    }
};

class Solution1 {
   public:
    ListNode *detectCycle(ListNode *head) {
        auto slow = head, fast = head ? head->next : nullptr;
        while (fast) {
            if (slow == fast) break;
            slow = slow->next;
            fast = fast->next;
            fast = fast ? fast->next : nullptr;
        }
        if (!fast) return nullptr;
        int cnt = 0;
        do {
            ++cnt;
            slow = slow->next;
            fast = fast->next->next;
        } while (slow != fast);
        slow = fast = head;
        while (cnt--) fast = fast->next;
        while (slow != fast) {
            slow = slow->next;
            fast = fast->next;
        }
        return slow;
    }
};

int main() { return 0; }