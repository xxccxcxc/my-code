#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <cstdio>
#include <cstring>
using namespace std;
const int M = 1050;
int main() {
    int n, bg, m;
    cin >> n >> bg >> m;
    bool f[2][M] = {0}; f[0][bg] = true;
    for (int i = 1, c; i <= n; i++) {
        cin >> c;
        int cur = i & 1;
        memset(f[cur], 0, sizeof(f[cur]));
        for (int j = 0, pre = cur ^ 1; j <= m; j++)
            if (f[pre][j]) {
                if (j - c >= 0) f[cur][j-c] = true;
                if (j + c <= m) f[cur][j+c] = true;
            }
    }
    for (int i = m, ed = n & 1; i >= 0; i--)
        if (f[ed][i]) { cout << i << endl; return 0; }
    cout << -1 << endl;
    return 0;
}
