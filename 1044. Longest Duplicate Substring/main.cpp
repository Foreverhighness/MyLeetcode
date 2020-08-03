#include <bits/stdc++.h>
using namespace std;
class Solution {
   public:
    string longestDupSubstring(string S) {
        const int n = S.length(), base = 26;
        auto chk = [&](int m) -> int {
            unsigned hash = 0, mul = 1;
            for (int i = 0; i < m; ++i) {
                hash = hash * base + (S[i] - 'a');
                mul *= base;
            }
            unordered_set<int> seen;
            seen.insert(hash);
            for (int head = 0, tail = m; tail != n; ++head, ++tail) {
                hash = hash * base - mul * (S[head] - 'a') + (S[tail] - 'a');
                if (seen.count(hash) > 0) return head + 1;
                seen.insert(hash);
            }
            return -1;
        };
        int l = 0, r = n;
        while (r - l > 1) {
            int m = (l + r) / 2;
            if (chk(m) != -1)
                l = m;
            else
                r = m;
        }
        int start = chk(l);
        if (start == -1) return "";
        return S.substr(start, l);
    }
};
string longestDupSubstring(string S) {
    int n = S.length();
    auto chk = [&](int m) -> int {
        unsigned hash = 0, mul = 1;
        unordered_set<int> seen;
        for (int i = 0; i < m; ++i) {
            mul *= 26;
            if (i == 0) mul = 1;
            hash = hash * 26 + S[i] - 'a';
        }
        int head = 0, tail = m;
        seen.insert(hash);
        auto calc = [&](int l, int len) -> unsigned {
            unsigned h = 0;
            for (int i = l; i < l + len; ++i) {
                h = h * 26 + S[i] - 'a';
            }
            return h;
        };
        cout << "[" << head << ", " << tail << "]: " << S.substr(head, m)
             << '\t' << hash << '\n';
        while (tail != n) {
            hash -= mul * (S[head] - 'a');
            unsigned h1 = hash, t1 = calc(head + 1, m - 1);
            hash *= 26;
            unsigned h2 = hash, t2 = calc(head + 1, m - 1) * 26;
            hash += S[tail] - 'a';
            unsigned h3 = hash, t3 = calc(head + 1, m);
            ++head, ++tail;
            cout << "[" << head << ", " << tail << "]: " << S.substr(head, m)
                 << '\t' << hash;
            if (h1 != t1)
                cout << "\tWrong_1!: should\t" << t1 << " get:\t" << h1;
            if (h2 != t2)
                cout << "\tWrong_2!: should\t" << t2 << " get:\t" << h2;
            if (h3 != t3)
                cout << "\tWrong_3!: should\t" << t3 << " get:\t" << h3;
            cout << '\n';
            if (seen.count(hash) > 0) return head;
            seen.insert(hash);
        }
        return -1;
    };
    int l = 0, r = n;
    l = 9;
    while (r - l > 1) {
        int m = (l + r) / 2;
        if (chk(m) == -1) {
            r = m;
        } else {
            l = m;
        }
    }
    int start = chk(l);
    if (start == -1) return "";
    return S.substr(start, l);
}

int main() {
    vector<string> in{
        "banana",
        "abcd",
        "aa",
        "abba",
        "ababdaebdabedeabbdddbcebaccececbccccebbcaaabaadcadccddaedaacaeddddecee"
        "deaabbbbcbacdaeeebaabdabdbaebadcbdebaaeddcadebedeabbbcbeadbaacdebceebc"
        "eeccddbeacdcecbcdbceedaeebdaeeabccccbcccbceabedaedaacdbbdbadcdbdddddcd"
        "ebbcdbcabbebbeabbdccccbaaccbbcecacaebebecdcdcecdeaccccccdbbdebaaaaaaea"
        "aeecdecedcbabedbabdedbaebeedcecebabedbceecacbdecabcebdcbecedccaeaaadba"
        "babdccedebeccecaddeabaebbeeccabeddedbeaadbcdceddceccecddbdbeeddabeddad"
        "aaaadbeedbeeeaaaeaadaebdacbdcaaabbacacccddbeaacebeeaabaadcabdbaadeacca"
        "ecbeaaabccddabbeacdecadebaecccbabeaceccaaeddedcaecddaacebcaecebebebada"
        "ceadcaccdeebbcdebcedaeaedacbeecceeebbdbdbaadeeecabdebbaaebdddeeddabcba"
        "aebeabbbcaaeecddecbbbebecdbbbaecceeaabeeedcdecdcaeacabdcbcedcbbcaeeeba"
        "abdbaadcebbccbedbabeaddaecdbdbdccceeccaccbdcdadcccceebdabccaebcddaeeec"
        "ddddacdbdbeebdabecdaeaadbadbebecbcacbbceeabbceecaabdcabebbcdecedbacbcc"
        "cddcecccecbacddbeddbbbadcbdadbecceebddeacbeeabcdbbaabeabdbbbcaeeadddae"
        "ccbcdabceeabaacbeacdcbdceebeaebcceeebdcdcbeaaeeeadabbecdbadbebbecdceae"
        "eecaaaedeceaddedbed",
    };
    for (auto&& s : in) {
        cout << "<------------------------------" << '\n';
        cout << Solution().longestDupSubstring(s) << '\n';
        cout << "------------------------------>" << '\n';
    }
    return 0;
}