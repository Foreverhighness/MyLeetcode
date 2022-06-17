#include <bits/stdc++.h>
using namespace std;
class Solution {
   public:
    void duplicateZeros(vector<int>& arr) {
        int n = arr.size(), i = -1, top = 0;
        while (top < n) {
            i++;
            if (arr[i] == 0) top++;
            top++;
        }
        int j = n - 1;
        if (top == n + 1) {
            arr[j] = 0;
            j--;
            i--;
        }
        while (j >= 0) {
            arr[j] = arr[i];
            j--;
            if (arr[i] == 0) arr[j] = 0, j--;
            i--;
        }
    }
};

int main() { return 0; }