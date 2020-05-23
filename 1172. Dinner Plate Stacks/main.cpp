#include <bits/stdc++.h>
using namespace std;

class DinnerPlates {
    vector<stack<int>*> V;
    priority_queue<int> Q;
    int cap, tail;
public:
    DinnerPlates(int capacity): cap(capacity), tail(-1) { }
    void push(int val) {
        if (Q.empty()) {
            V.push_back(new stack<int>());
            Q.push(-(tail + 1));
        }
        int idx = -Q.top();
        stack<int>* S = V[idx];
        S->push(val);
        if (tail < idx) {
            tail = idx;
        }
        if (S->size() == cap) {
            Q.pop();
        }
    }
    
    int pop() {
        return popAtStack(tail);
    }
    
    int popAtStack(int index) {
        if (index < 0 || tail < index || V[index]->size() == 0) return -1;
        
        stack<int>* S = V[index];
        int ret = S->top();
        if (S->size() == cap) {
            Q.push(-index);
        }
        S->pop();
        while (tail != -1 && V[tail]->size() == 0) {
            --tail;
        }
        return ret;
    }
};

/**
 * Your DinnerPlates object will be instantiated and called as such:
 * DinnerPlates* obj = new DinnerPlates(capacity);
 * obj->push(val);
 * int param_2 = obj->pop();
 * int param_3 = obj->popAtStack(index);
 */