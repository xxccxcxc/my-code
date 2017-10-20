#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <cstdio>
#include <cstring>
using namespace std;
const int N = 500050;
int a[N], b[N];
long long ans;

void merge(int l, int r) {
    if (l == r) return;
    int mid = (l+r)/2;
    merge(l, mid);
    merge(mid+1, r);
    int i = l, j = mid+1, k = l;
    while (i <= mid && j <= r) {
        if (a[i] <= a[j]) b[k++] = a[i++];
        else ans += mid-i+1, b[k++] = a[j++];
    }
    while (i <= mid) b[k++] = a[i++];
    while (j <= r) b[k++] = a[j++];
    for (int i = l; i <= r; i++)
        a[i] = b[i];
}

int main() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    merge(1, n);
    cout << ans << endl;
    return 0;
}

