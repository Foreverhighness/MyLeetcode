#include <bits/stdc++.h>
using namespace std;

int shortestSubarray(vector<int>& A, int K) {
    vector<int> sum(A.size() + 1);
    deque<int> deq;
    int ans = A.size() + 1;

    for (int i = 0, val = 0; i != A.size(); ++i) {
        val += A[i];
        sum[i + 1] = val;
    }
    
    for (int i = 0; i != sum.size(); ++i) {
        while (!deq.empty() && sum[i] <= sum[deq.back()]) {
            deq.pop_back();
        }
        while (!deq.empty() && sum[i] - sum[deq.front()] >= K) {
            ans = min(ans, i - deq.front());
            deq.pop_front();
        }
        deq.push_back(i);
    }
    return ans == A.size() + 1 ? -1: ans;
}

int main()
{
    int T;
    cin >> T;
    // cout << "T: " << T << '\n';
    while (T--) {
        int n, k; cin >> n >> k;
        vector<int> vec(n);
        // cout << "n: " << n << "  k: " << k << '\n';
        for (int i = 0, t; i != n; ++i) {
            cin >> t;
            vec.push_back(t);
        }

        // cout << "Size: " << vec.size() << "\n" << "vec: ";
        // for (int i = 0; i != vec.size(); ++i) {
        //     cout << vec[i] << " ";
        // }
        // cout << '\n';

        cout << shortestSubarray(vec, k) << endl;
    }
    return 0;
}
/*
Input:
3
1 1
1
2 4
1 2
3 3
2 -1 2

Output:
1
-1
3
*/
int shortestSubarrayWithDebug(vector<int>& A, int K) {
    vector<int> sum(A.size() + 1);
    deque<int> deq;
    int ans = A.size() + 1;

    for (int i = 0, val = 0; i != A.size(); ++i) {
        val += A[i];
        sum[i + 1] = val;
    }
    cout << "A: ";
    for (int i = 0; i != A.size(); ++i) {
        cout << A[i] << " ";
    }
    cout << '\n';
    
    cout << "Sum: ";
    for (int i = 0; i != sum.size(); ++i) {
        cout << sum[i] << " ";
    }
    cout << '\n';
    
    // deq.push_back(0);
    for (int i = 0; i != sum.size(); ++i) {
        while (!deq.empty() && sum[i] <= sum[deq.back()]) {
            cout << "Pop_back: " << deq.back() << '\n';
            deq.pop_back();
        }
        while (!deq.empty() && sum[i] - sum[deq.front()] >= K) {
            cout << "Pop_front: " << deq.front() << '\n';
            ans = min(ans, i - deq.front());
            deq.pop_front();
        }
        cout << "Push_back: " << i << '\n';
        deq.push_back(i);
    }
    cout << "out: " << (ans == A.size() + 1 ? -1: ans) << endl;
    return ans == A.size() + 1 ? -1: ans;
}

