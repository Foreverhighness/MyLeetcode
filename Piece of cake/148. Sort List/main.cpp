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
   public:
    int getLength(ListNode *head) {
        int ret = 0;
        for (; head; head = head->next) ++ret;
        return ret;
    }
    auto mergeList(ListNode *left, ListNode *right) {
        ListNode dummy, *cur = &dummy;
        while (left && right) {
            auto &nxt = left->val < right->val ? left : right;
            cur->next = nxt;
            nxt = nxt->next;
            cur = cur->next;
        }
        cur->next = left ? left : right;
        while (cur->next) cur = cur->next;
        return make_pair(dummy.next, cur);
    }
    ListNode *splitList(ListNode *head, int size) {
        if (head == nullptr) return nullptr;
        while (head->next && --size) head = head->next;
        ListNode *ret = head->next;
        head->next = nullptr;
        return ret;
    }
    ListNode *sortList(ListNode *head) {
        int len = getLength(head);
        ListNode dummy(-1, head);
        for (int block = 1; block < len; block <<= 1) {
            ListNode *cur = &dummy;
            while (cur->next) {
                ListNode *left = cur->next;
                ListNode *right = splitList(left, block);
                if (right == nullptr) break;
                ListNode *nxt = splitList(right, block);
                auto [head, tail] = mergeList(left, right);
                cur->next = head;
                tail->next = nxt;
                cur = tail;
            }
        }
        return dummy.next;
    }
};

int main() { return 0; }