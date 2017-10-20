#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
using namespace std;
typedef long long ll;
const ll T = 33554432LL*33554432LL;
const int L = 500;
ll a[L+5];
void work(ll c, int k){
    while (k--)
    {
        ll x = 0;
        for (int j = 1; j <= L; j++)
        {
            a[j] = a[j] * c + x;
            x = a[j] / 10;
            a[j] %= 10;
        }
    }
}
int main(){
    int n;
    cin >> n;
    cout << int(log(2)/log(10)*n+1) << endl;
    a[1] = 1;
    work(T, n/50);
    work(2, n%50);
    --a[1];
    for (int i = 500; i >= 1; i--){
        cout << a[i];
        if (i % 50 == 1)
            cout << endl;
    }
    return 0;
}

