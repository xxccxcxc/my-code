#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
typedef long long LL;
const int N = 20500000;
const LL MOD = 20100403;

LL n, m, f[N], g[N];

LL qpow(LL a, LL k) {
    LL ret = 1;
    while (k) {
        if (k&1) ret = ret * a % MOD;
        a = a * a % MOD;
        k >>= 1;
    }
    return ret;
}

LL C(LL a, LL b) {
    return f[a] * g[b] % MOD * g[a-b] % MOD;
}

int main() {
    f[0] = 1;
    cin >> n >> m;
    for (int i = 1; i <= n+m; i++)
        f[i] = f[i-1] * i % MOD;
    g[n+m] = qpow(f[n+m], MOD-2);
    for (int i = n+m-1; i >= 1; i--)
        g[i] = g[i+1] * (i+1) % MOD;
    cout << (C(n+m, m) - C(n+m, m-1) + MOD) % MOD;
    return 0;
}
