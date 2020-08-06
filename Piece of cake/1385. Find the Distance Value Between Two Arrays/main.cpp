#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
        int res = arr1.size();
        for (int x: arr1) {
            for (int y: arr2) {
                if (abs(x - y) <= d) {
                    --res;
                    break;
                }
            }
        }
        return res;
    }
};

int main()
{
    return 0;
}