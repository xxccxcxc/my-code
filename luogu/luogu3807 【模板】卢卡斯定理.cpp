#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
typedef long long LL;
const int N = 100000;
LL f[N+50] = {1};
LL T, n, m, p;

LL qpow(LL a, LL k) {
    LL ret = 1;
    while (k) {
        if (k&1) ret = ret * a % p;
        a = a * a % p;
        k >>= 1;
    }
    return ret;
}

LL C(int a, int b) {
    return f[a] * qpow(f[b], p-2) % p * qpow(f[a-b], p-2) % p;
}

LL lucas(LL a, LL b) {
    LL ans = 1;
    while (b) {
        LL c = a%p, d = b%p;
        if (c < d) return 0;
        ans = ans * C(c, d) % p;
        a /= p; b /= p;
    }
    return ans;
}

int main() {
    cin >> T;
    while (T--) {
        cin >> n >> m >> p;
        for (LL i = 1; i < p; i++)
            f[i] = f[i-1] * i % p;
        cout << lucas(n+m, m) << endl;
    }
    return 0;
}

