#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;
typedef long long LL;
LL x, y, g;
void exgcd(LL a, LL b) {
    if (!b) {
        x = 1;
        y = 0;
        g = a;
        return;
    }
    exgcd(b, a%b);
    int tmp = x;
    x = y;
    y = tmp-a/b*y;
}
int main() {
    LL a, b;
    cin >> a >> b;
    exgcd(a, b);
    cout << (x%b+b)%b << endl;
    return 0;
}

