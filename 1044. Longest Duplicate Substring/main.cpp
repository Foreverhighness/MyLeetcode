#include <bits/stdc++.h>
using namespace std;
string longestDupSubstring(string S) {
    int n = S.length();
    auto chk = [&](int m) -> int {
        unsigned hash = 0, acc = 1;
        unordered_set<int> vis;
        for (int i = 0; i < m; ++i) {
            acc *= 26;
            if (i == 0) acc = 1;
            hash = hash * 26 + S[i] - 'a';
        }
        int head = 0, tail = m;
        vis.insert(hash);
        auto calc = [&](int l, int le) -> unsigned {
            unsigned h = 0;
            for (int i = l; i < l + le; ++i) {
                h = h * 26 + S[i] - 'a';
            }
            return h;
        };
        cout << "[" << head << ", " << tail << "]: " << S.substr(head, m) << '\t' << hash << '\n';
        while (tail != n) {
            hash -= acc * (S[head] - 'a');
            unsigned h1 = hash, t1 = calc(head+1,m-1);
            hash *= 26;
            unsigned h2 = hash, t2 = calc(head+1,m-1)*26;
            hash += S[tail] - 'a';
            unsigned h3 = hash, t3 = calc(head+1, m);
            ++head, ++tail;
            cout << "[" << head << ", " << tail << "]: " << S.substr(head, m) << '\t' << hash;
            if (h1 != t1) cout << "\tWrong_1!: should\t" << t1 << " get:\t" << h1;
            if (h2 != t2) cout << "\tWrong_2!: should\t" << t2 << " get:\t" << h2;
            if (h3 != t3) cout << "\tWrong_3!: should\t" << t3 << " get:\t" << h3;
            cout << '\n';
            if (vis.count(hash) > 0) return head;
            vis.insert(hash);
        }
        return -1;
    };
    int l = 0, r = n;
    l = 9;
    // while (r - l > 1) {
    //     int m = (l + r) / 2;
    //     if (chk(m) == -1) {
    //         r = m;
    //     } else {
    //         l = m;
    //     }
    // }
    int start = chk(l);
    if (start == -1) return "";
    return S.substr(start, l);
}

int main()
{
    vector<string> in{
        // "banana", 
        // "abcd", 
        // "aa", 
        // "abba",
        "ababdaebdabedeabbdddbcebaccececbccccebbcaaabaadcadccddaedaacaeddddeceedeaabbbbcbacdaeeebaabdabdbaebadcbdebaaeddcadebedeabbbcbeadbaacdebceebceeccddbeacdcecbcdbceedaeebdaeeabccccbcccbceabedaedaacdbbdbadcdbdddddcdebbcdbcabbebbeabbdccccbaaccbbcecacaebebecdcdcecdeaccccccdbbdebaaaaaaeaaeecdecedcbabedbabdedbaebeedcecebabedbceecacbdecabcebdcbecedccaeaaadbababdccedebeccecaddeabaebbeeccabeddedbeaadbcdceddceccecddbdbeeddabeddadaaaadbeedbeeeaaaeaadaebdacbdcaaabbacacccddbeaacebeeaabaadcabdbaadeaccaecbeaaabccddabbeacdecadebaecccbabeaceccaaeddedcaecddaacebcaecebebebadaceadcaccdeebbcdebcedaeaedacbeecceeebbdbdbaadeeecabdebbaaebdddeeddabcbaaebeabbbcaaeecddecbbbebecdbbbaecceeaabeeedcdecdcaeacabdcbcedcbbcaeeebaabdbaadcebbccbedbabeaddaecdbdbdccceeccaccbdcdadcccceebdabccaebcddaeeecddddacdbdbeebdabecdaeaadbadbebecbcacbbceeabbceecaabdcabebbcdecedbacbcccddcecccecbacddbeddbbbadcbdadbecceebddeacbeeabcdbbaabeabdbbbcaeeadddaeccbcdabceeabaacbeacdcbdceebeaebcceeebdcdcbeaaeeeadabbecdbadbebbecdceaeeecaaaedeceaddedbed",
    };
    for (auto&& s: in) {
        cout << "<-------------------" << '\n';
        cout << longestDupSubstring(s) << '\n';
        cout << "------------------->" << '\n';
    }
    return 0;
}