#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maxCandies(vector<int>& status, vector<int>& candies, vector<vector<int>>& keys, vector<vector<int>>& containedBoxes, vector<int>& initialBoxes) {
        int n = status.size(), res = 0;
        queue<int> que;
        set<int> mykey, mybox;
        for (int box: initialBoxes) {
            if (status[box] == 0) {
                mybox.insert(box);
            } else {
                que.push(box);
            }
        }
        while (!que.empty()) {
            int cur = que.front(); que.pop();
            res += candies[cur];
            mykey.insert(keys[cur].begin(), keys[cur].end());
            for (int box: containedBoxes[cur]) {
                if (status[box] == 0) {
                    mybox.insert(box);
                } else {
                    que.push(box);
                }
            }
            vector<int> ivec(min(mybox.size(), mykey.size()));
            auto it = set_intersection(mybox.begin(),mybox.end(),mykey.begin(),mykey.end(),ivec.begin());
            ivec.resize(it - ivec.begin());
            for (int box: ivec) {
                mykey.erase(box);
                mybox.erase(box);
                que.push(box);
            }
        }
        return res;
    }
};
int main()
{
    
    return 0;
}