#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <cmath>
using namespace std;
const int N = 150;
const double EPS = 1e-8;
int n;
double a[N][N];

int sgn(double x) {
    if (x > EPS) return 1;
    if (x < -EPS) return -1;
    return 0;
}

void work(int j, int i, double t) {
    for (int k = 1; k <= n+1; k++)
         a[j][k] -= a[i][k] * t;
}

void gauss() {
    for (int i = 1; i <= n; i++) {
        int mx = i;
        for (int j = i+1; j <= n; j++)
             if (fabs(a[j][i]) > fabs(a[mx][i]))
                 mx = j;
        if (!sgn(a[mx][i])) {
            printf("No Solution\n");
            return;
        }
        swap(a[i], a[mx]);
        for (int j = 1; j <= n; j++)
             if (j != i)
                 work(j, i, a[j][i] / a[i][i]);
    }
    for (int i = 1; i <= n; i++)
        printf("%.2lf\n", a[i][n+1] / a[i][i]);
}

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n+1; j++)
            cin >> a[i][j];
    gauss();
    return 0;
}

