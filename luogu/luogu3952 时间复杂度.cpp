#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <string>
#include <cmath>
using namespace std;
int n, level;
bool p[300];

int dfs(int cur, bool first) {
    int ret = 0;
    bool die = false;
    while (n) {
        char typ;
        cin >> typ;
        --n;
        if (typ =='E')  {
            getchar();
            if (die) return -1;
            return ~cur ? cur + ret : 0;
        }
        char nam, r1[5], r2[5];
        cin >> nam >> r1 >> r2;
        if (p[nam]) die = true;
        int l = 0, r = 0;
        if (r1[0] != 'n') sscanf(r1, "%d", &l);
        if (r2[0] != 'n') sscanf(r2, "%d", &r);
        int vlevel = -1;
        if (l && r && l <= r) vlevel = 0;
        else if (l && !r) vlevel = 1;
        else if (!l && !r) vlevel = 0;
        p[nam] = true;
        int tmp = dfs(vlevel, false);
        if (tmp == -1) die = true;
        ret = max(ret, tmp);
        p[nam] = false;
    }
    if (!first && !n) die = true;
    if (die) return -1;
    return ~cur ? cur + ret : 0;
}

int main() {
    int T;
    for (scanf("%d", &T); T--; ) {
        memset(p, 0, sizeof(p));
        scanf("%d O(", &n);
        if (getchar() == '1') level = 0;
        else scanf("^%d", &level);
        getchar();
        int ans = dfs(0, true);
        if (n) {
            ans = -1;
            string tmp;
            while (n--) getline(cin, tmp);
        }
        if (ans == -1) printf("ERR\n");
        else if (ans == level) printf("Yes\n");
        else printf("No\n");
    }
    return 0;
}


