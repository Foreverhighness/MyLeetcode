#include <bits/stdc++.h>
using namespace std;
class Solution {
    template <typename ITER>
    bool Next_permutation(ITER first, ITER last) {
        ITER left = last;
        if (first == left || first == --left) return false;
        for (;;) {
            ITER right = left;
            if (*--left < *right) {
                ITER mid = last;
                while (!(*left < *--mid)) {
                }
                iter_swap(left, mid);
                Reverse(right, last);
                return true;
            }
            if (first == left) {
                Reverse(first, last);
                return false;
            }
        }
    }
    template <typename ITER>
    void Reverse(ITER first, ITER last) {
        if (first == last) return;
        --last;
        while (first < last) {
            iter_swap(first, last);
            ++first;
            --last;
        }
    }

   public:
    void reverseString(vector<char>& s) {
        // next_permutation(s.begin(), s.end());
        // Next_permutation(s.begin(), s.end());

        // reverse(s.begin(), s.end());
        Reverse(s.begin(), s.end());
    }
};

int main() { return 0; }