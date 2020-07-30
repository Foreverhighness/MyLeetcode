#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
class Solution_Space_O1 {
    inline bool check(ListNode* head) {
        return head == NULL || head->next == NULL;
    }
    inline ListNode* findMiddle(ListNode* head) {
        if (check(head)) return head;
        ListNode *middle = head, *last = head->next;
        while (last && last->next) {
            middle = middle->next;
            last = last->next->next;
        }
        return middle;
    }
    inline ListNode* reverseList(ListNode* q) {
        ListNode* p = NULL;
        while (q) {
            ListNode* r = q->next;
            q->next = p;
            p = q;
            q = r;
        }
        return p;
    }
public:
    bool isPalindrome(ListNode* head) {
        if (check(head)) return true;
        ListNode *middle = findMiddle(head);
        ListNode *q = reverseList(middle->next), *p = head;
        while (q) {
            if (p->val != q->val)
                return false;
            p = p->next;
            q = q->next;
        }
        return true;
    }
};

class Solution_Space_On {
public:
    bool isPalindrome(ListNode* head) {
        stack<int> stk;
        ListNode* p = head;
        while (p) {
            stk.push(p->val);
            p = p->next;
        }
        p = head;
        while (p) {
            if (stk.top() != p->val)
                return false;
            stk.pop();
            p = p->next;
        }
        return true;
    }
};

int main()
{
    
    return 0;
}
/*
[]
[1]
[1,1]
[1,2]
[1,2,1]
[1,1,1]
[1,2,2]
[1,2,2,1]
[1,2,1,2]
*/