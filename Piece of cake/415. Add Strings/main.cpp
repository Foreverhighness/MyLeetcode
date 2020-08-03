#include <bits/stdc++.h>
using namespace std;
class Solution {
   public:
    string addStrings(string num1, string num2) {
        int n = num1.length(), m = num2.length();
        if (n < m) {
            swap(n, m);
            num1.swap(num2);
        }
        reverse(num1.begin(), num1.end());
        reverse(num2.begin(), num2.end());
        int carry = 0, i;
        for (i = 0; i < m; ++i) {
            int n1 = num1[i] - '0', n2 = num2[i] - '0', t = n1 + n2 + carry;
            carry = 0;
            if (t >= 10) {
                t -= 10;
                carry = 1;
            }
            num1[i] = t + '0';
        }
        while (carry && i < n) {
            int t = num1[i] - '0' + carry;
            carry = 0;
            if (t >= 10) {
                t -= 10;
                carry = 1;
            }
            num1[i++] = t + '0';
        }
        if (i == n && carry) num1.push_back('1');
        reverse(num1.begin(), num1.end());
        return num1;
    }
};

int main() { return 0; }