#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;
const int N = 2050;
int T, k, n, m, a[N+5][N+5], f[N+5][N+5];
void init() {
    a[0][0] = 1; f[0][0] = 0;
    for (int i = 1; i < N; i++) {
        f[i][0] = 0;
        a[i][0] = a[i][i] = 1;
        for (int j = 1; j < i; j++) {
            a[i][j] = (a[i-1][j-1] + a[i-1][j]) % k;
            f[i][j] = f[i-1][j] + f[i][j-1] - f[i-1][j-1] + (!a[i][j]);
        }
        f[i][i] = f[i][i-1];
    }
}
int main() {
    cin >> T >> k;
    init();
    while (T--) {
        scanf("%d%d", &n, &m);
        printf("%d\n", f[n][min(n, m)]);
    }
    return 0;
}

