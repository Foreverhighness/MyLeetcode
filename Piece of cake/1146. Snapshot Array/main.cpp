#include <bits/stdc++.h>
using namespace std;
class SnapshotArray {
    using P = pair<int, int>;
    vector<vector<P>> vec;
    int snap_id;

   public:
    SnapshotArray(int length) {
        snap_id = 0;
        vec.resize(length, {P(0, 0)});
    }

    void set(int index, int val) {
        if (vec[index].back().first == snap_id) {
            vec[index].back().second = val;
        } else {
            vec[index].emplace_back(snap_id, val);
        }
    }

    int snap() { return snap_id++; }

    int get(int index, int snap_id) {
        auto it = upper_bound(vec[index].begin(), vec[index].end(), P(snap_id, 1 << 30));
        --it;
        return it->second;
    }
};

/**
 * Your SnapshotArray object will be instantiated and called as such:
 * SnapshotArray* obj = new SnapshotArray(length);
 * obj->set(index,val);
 * int param_2 = obj->snap();
 * int param_3 = obj->get(index,snap_id);
 */

int main() { return 0; }