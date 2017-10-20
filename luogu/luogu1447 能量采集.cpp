#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <cstdio>
#include <cstring>
using namespace std;
typedef long long LL;
const int N = 100050;
int main() {
    int n, m;
    cin >> n >> m;
    if (n > m) swap(n, m); 
    LL f[N] = {0}, ans = 0;
    for (int i = n; i >= 1; i--) {
        f[i] = LL(n/i) * LL(m/i);
        for (int j = i+i; j <= n; j += i)
            f[i] -= f[j];
        ans += (2*i-1) * f[i];
    }
    cout << ans << endl;
    return 0;
}

