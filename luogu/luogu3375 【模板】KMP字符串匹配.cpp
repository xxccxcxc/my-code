#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cstring>
using namespace std;
const int N = 1000050, M = 1050;

int nxt[M];

void getnext(const string &p) {
    memset(nxt, 0, sizeof(nxt));
    int lp = p.size();
    for (int i = 1, k = 0; i < lp; i++) {
        while (k && p[i] != p[k])
            k = nxt[k-1];
        if (p[i] == p[k]) ++k;
        nxt[i] = k;
    }
}

void kmp(const string &s, const string &p) {
    getnext(p);
    int ls = s.size(), lp = p.size();
    for (int i = 0, j = 0; i < ls; i++) {
        while (j && s[i] != p[j])
            j = nxt[j-1];
        if (s[i] == p[j]) ++j;
        if (j == lp) {
            printf("%d\n", i - lp + 2);
            j = nxt[j-1];
        }
    }
    for (int i = 0; i < lp; i++)
        printf("%d ", nxt[i]);
    puts("");
}

int main() {
    string s, p;
    cin >> s >> p;
    kmp(s, p);
    return 0;
}

