#include <bits/stdc++.h>
using namespace std;
int cnt7 = 0;
int rand7() {
    static mt19937 rng(random_device{}());
    static uniform_int_distribution<> dist(1, 7);
    ++cnt7;
    int ret = dist(rng);
    return ret;
}

class Solution {
public:
    int rand10() {
        for (;;) {
            int a = rand7(), b = rand7();
            int first = (a - 1) * 7 + b;
            if (first <= 40) return (first - 1) % 10 + 1;

            a = first - 40, b = rand7();
            int second = (a - 1) * 7 + b;
            if (second <= 60) return (second - 1) % 10 + 1;

            a = second - 60, b = rand7();
            int third = (a - 1) * 7 + b;
            if (third <= 20) return (third - 1) % 10 + 1;
        }
    }
};

int main(int argc, char* argv[])
{
    int n = 1e5;
    Solution sol;
    if (argc == 2) {
        int k = atoi(argv[1]);
        n = 1;
        while (k--) n *= 10;
        cout << "N: " << n << endl;
    }
    array<int, 11> cnt = {};
    for (int i = 0; i < n; ++i)
        ++cnt[sol.rand10()];
    for (int i = 1; i <= 10; ++i) {
        cout << i << ": " << cnt[i] << endl;
    }
    cout << "call rand7:\t" << cnt7 << endl;
    cout << "call rand10:\t" << n << endl;
    cout << "avg: " << static_cast<double>(cnt7) / n << endl;
    return 0;
}