#include <bits/stdc++.h>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        ListNode dummySmall(-1), *tailSmall = &dummySmall;
        ListNode dummyBig(-1), *tailBig = &dummyBig;
        while (head) {
            ListNode *&p = head->val < x ? tailSmall : tailBig;
            p->next = head;
            p = p->next;
            head = head->next;
        }
        tailSmall->next = dummyBig.next;
        tailBig->next = NULL;
        return dummySmall.next;
    }
};

int main()
{
    
    return 0;
}
class Solution_Space_On {
public:
    ListNode* partition(ListNode* p, int x) {
        ListNode head(-1), *tail = &head;
        while (p) {
            ListNode* t = new ListNode(p->val);
            if (p->val < x) {
                if (head.next == NULL)
                    tail = t;
                t->next = head.next;
                head.next = t;
            } else {
                tail->next = t;
                tail = tail->next;
            }
            p = p->next;
        }
        return head.next;
    }
};