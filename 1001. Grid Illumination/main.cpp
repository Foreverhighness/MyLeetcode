#include <vector>
#include <unordered_map>
#include <unordered_set>
using namespace std;
class Solution {
public:
    vector<int> gridIllumination(int N, vector<vector<int>>& lamps, vector<vector<int>>& queries) {
        unordered_map<int, int> row, col, rup, lup;
        unordered_set<uint64_t> has;
        vector<int> res(queries.size());
        for (auto& v: lamps) {
            int x = v[0], y = v[1];
            has.insert((uint64_t)x<<32|y);
            ++row[x], ++col[y], ++rup[x+y], ++lup[x-y];
        }
        for (int i = 0; i != queries.size(); ++i) {
            int x = queries[i][0], y = queries[i][1];
            if (row[x] == 0 && col[y] == 0 && rup[x+y] == 0 && lup[x-y] == 0) {
                res[i] = 0;
            } else {
                res[i] = 1;
                for (int dx = -1; dx != 2; ++dx) {
                    for (int dy = -1; dy != 2; ++dy) {
                        int nx = x + dx, ny = y + dy;
                        if (has.find((uint64_t)nx<<32|ny) != has.end()) {
                            --row[nx], --col[ny], --rup[nx+ny], --lup[nx-ny];
                            has.erase((uint64_t)nx<<32|ny);
                        }
                    }
                }
            }
        }
        return res;
    }
};