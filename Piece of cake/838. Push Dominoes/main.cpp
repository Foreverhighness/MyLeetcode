#include <bits/stdc++.h>
using namespace std;
class Solution {
   public:
    string pushDominoes(string dominoes) {
        int n = dominoes.length(), forces[n];
        memset(forces, 0, sizeof(forces));
        for (int i = 0, f = 0; i < n; ++i) {
            if (dominoes[i] == 'R')
                f = n;
            else if (dominoes[i] == 'L')
                f = 0;
            else
                f = f ? f - 1 : 0;
            forces[i] += f;
        }
        for (int i = n - 1, f = 0; i >= 0; --i) {
            if (dominoes[i] == 'R')
                f = 0;
            else if (dominoes[i] == 'L')
                f = n;
            else
                f = f ? f - 1 : 0;
            forces[i] -= f;
        }
        for (int i = 0; i < n; ++i) {
            if (forces[i] == 0)
                dominoes[i] = '.';
            else if (forces[i] > 0)
                dominoes[i] = 'R';
            else
                dominoes[i] = 'L';
        }
        return dominoes;
    }
};

class Solution1 {
   public:
    string pushDominoes(string dominoes) {
        int n = dominoes.length(), l[n], r[n];
        for (int i = 0, prv = 0; i < n; ++i) {
            if (dominoes[i] != '.') prv = i;
            l[i] = prv;
        }
        for (int i = n - 1, prv = n - 1; i >= 0; --i) {
            if (dominoes[i] != '.') prv = i;
            r[i] = prv;
        }
        for (int i = 0; i < n; ++i) {
            if (dominoes[i] != '.') continue;
            if (dominoes[l[i]] == 'R' && dominoes[r[i]] == 'L') {
                int R = i - l[i], L = r[i] - i;
                if (R < L)
                    dominoes[i] = 'R';
                else if (R > L)
                    dominoes[i] = 'L';
            } else if (dominoes[l[i]] == 'R') {
                dominoes[i] = 'R';
            } else if (dominoes[r[i]] == 'L') {
                dominoes[i] = 'L';
            }
        }
        return dominoes;
    }
};

int main() {
    vector<string> input{".L.R...LR..L..", "RR.L"};
    for (auto s : input) cout << Solution().pushDominoes(s) << endl;
    return 0;
}