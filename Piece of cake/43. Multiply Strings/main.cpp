#include <bits/stdc++.h>
using namespace std;
class Solution {
   public:
    string multiply(string num1, string num2) {
        if (num1 == "0" || num2 == "0") return "0";
        int n = num1.length(), m = num2.length();
        reverse(num1.begin(), num1.end());
        reverse(num2.begin(), num2.end());
        string res(n + m, 0);
        for (int i = 0; i < n; ++i) {
            int n1 = num1[i] - '0';
            for (int j = 0; j < m; ++j) {
                int n2 = num2[j] - '0';
                int t = n1 * n2;
                res[i + j] += t;
                while (res[i + j] >= 10) {
                    res[i + j + 1] += 1;
                    res[i + j] -= 10;
                }
            }
        }
        int k = n + m;
        while (res[--k] == 0) {
        }
        for (int i = 0; i <= k; ++i) res[i] += '0';
        res = res.substr(0, k + 1);
        reverse(res.begin(), res.end());
        return res;
    }
};

int main() { return 0; }