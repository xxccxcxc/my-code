#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <cstdio>
#include <cstring>
using namespace std;
typedef long long ll;
const ll MOD = 100003; 
ll quickPow(ll a, ll b) {
    ll tmp = a, ret = 1;
    while (b) {
        if (b&1) ret = ret * tmp % MOD;
        tmp = tmp * tmp % MOD;
        b >>= 1;
    }
    return ret;
}
int main() {
    ll m, n;
    cin >> m >> n;
    cout << ((quickPow(m, n) - m*quickPow(m-1, n-1)) % MOD + MOD) % MOD << endl;
    return 0;
}

