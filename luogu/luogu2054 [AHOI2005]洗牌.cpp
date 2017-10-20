#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
typedef long long LL;
LL n, m, L, x, y;
LL ksm(LL a, int k) {
    LL ret = 1;
    while (k) {
        if (k&1) ret = ret * a % (n+1);
        a = a * a % (n+1);
        k >>= 1;
    }
    return ret;
}
void exgcd(LL a, LL b) {
    if (!b) {
        x = 1;
        y = 0;
        return;
    }
    exgcd(b, a%b);
    int tmp = x;
    x = y;
    y = tmp-a/b*y;
}
int main() {
    cin >> n >> m >> L;
    LL a = ksm(2, m), b = n+1, c = L;
    exgcd(a, b);
    x = (x * c % b + b) % b;
    cout << x << endl;
    return 0;
}

