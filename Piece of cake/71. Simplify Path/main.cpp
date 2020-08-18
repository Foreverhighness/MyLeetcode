#include <bits/stdc++.h>
using namespace std;
class Solution {
   public:
    string simplifyPath(string path) {
        path.push_back('/');
        string_view path_view(path);
        int n = path_view.size();
        vector<string_view> res;
        for (int i = 0, len = 1; i < n; i += len + 1, len = 1) {
            while (i < n && path_view[i] == '/') ++i;
            if (i == n) break;
            while (path_view[i + len] != '/') ++len;
            string_view tmp = path_view.substr(i, len);
            if (tmp == "..") {
                if (!res.empty()) res.pop_back();
            } else if (tmp != ".") {
                res.push_back(tmp);
            }
        }
        if (res.empty()) return "/";
        string ret;
        for_each(res.begin(), res.end(), [&ret](auto str) {
            ret += "/";
            ret += str;
        });
        return ret;
    }
};

int main() { return 0; }