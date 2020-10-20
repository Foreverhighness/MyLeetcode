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

class Solution {
    ListNode* findMiddle(ListNode* head) {
        if (!head || !head->next) return head;
        ListNode *slow = head, *fast = head->next;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
    ListNode* reverseList(ListNode* q) {
        ListNode *p = nullptr;
        while (q) {
            ListNode *r = q->next;
            q->next = p;
            p = q;
            q = r;
        }
        return p;
    }
    void mergeList(ListNode* left, ListNode* right) {
        while (left) {
            ListNode *tmp = left->next;
            left->next = right;
            left = tmp;
            swap(left, right);
        }
    }
public:
    void reorderList(ListNode* head) {
        if (!head) return;
        ListNode* mid = findMiddle(head);
        ListNode* right = mid->next;
        mid->next = nullptr;
        right = reverseList(right);
        mergeList(head, right);
    }
};

int main()
{
    return 0;
}