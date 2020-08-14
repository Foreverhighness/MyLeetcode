#include <bits/stdc++.h>

void reverse(char* s, int first, int last) {
    while (first < last) {
        char t = s[first];
        s[first] = s[last];
        s[last] = t;
        ++first;
        --last;
    }
}

char* reverseWords(char* s) {
    int pos = -1, i = 0, first = -1, last = -2, n = strlen(s);
    while (i < n) {
        char ch = s[i];
        if (ch == ' ') {
            if (first != -1)
                reverse(s, first, last);
            first = -1;
            if (pos == last)
                s[++pos] = ' ';
        } else {
            s[++pos] = ch;
            if (first == -1)
                first = pos;
            last = pos;
        }
        ++i;
    }
    if (last == -2) return s[0] = '\0', s;
    if (first != -1)
        reverse(s, first, last);
    s[last + 1] = '\0';
    reverse(s, 0, last);
    return s;
}

int main() { return 0; }