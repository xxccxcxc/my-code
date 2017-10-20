#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;
typedef long long LL;
const int N = 50050;
int n, m;
LL s[N], f[N], q[N];
int h, t;
LL getf(int i, int j)
{
    return f[j] + (s[i]-s[j]-m-1) * (s[i]-s[j]-m-1);
}
LL getup(int i, int j)
{
    return (f[i] + s[i]*s[i]) - (f[j] + s[j]*s[j]);
}
LL getdown(int i, int j)
{
    return (s[i]-s[j])*2;
}
int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> s[i];
        s[i] += s[i-1] + 1;
    }
    q[h=t=1] = 0;
    for (int i = 1; i <= n; i++)
    {
        while (h < t && getup(q[h+1], q[h]) <= (s[i]-m-1) * getdown(q[h+1], q[h]))
            ++h;
        f[i] = getf(i, q[h]);
        while (h < t && getup(i, q[t]) * getdown(q[t], q[t-1]) <= getup(q[t], q[t-1]) * getdown(i, q[t]))
            --t;
        q[++t] = i;
    }
    cout << f[n] << endl;
    return 0;
}

