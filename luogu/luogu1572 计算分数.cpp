#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <cstdio>
#include <cstring>
using namespace std;
int gcd(int a, int b) {
    return b ? gcd(b, a%b) : a;
}
int main() {
    int a = 0, b = 1, c, d;
    while (scanf("%d/%d", &c, &d) == 2) {
        int g = gcd(b, d);
        a = (a * d + c * b) / g;
        b *= d / g;
        int g2 = gcd(a, b);
        a /= g2; b /= g2;
        if (b < 0) a = -a, b = -b;
    }
    if (b == 1) cout << a << endl;
    else printf("%d/%d\n", a, b);
    return 0;
}

