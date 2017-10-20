#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <cstdio>
#include <cstring>
using namespace std;
const int N = 10050;
int main()
{
    int n, k, a[N];
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    sort(a+1, a+n+1);
    int cnt = unique(a+1, a+n+1) - (a+1);
    if (k > cnt) cout <<"NO RESULT" << endl;
    else cout << a[k] << endl;
    return 0;
}

