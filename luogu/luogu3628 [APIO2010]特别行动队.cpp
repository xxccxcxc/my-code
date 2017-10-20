#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
typedef long long LL;
const int N = 1000050;
int n;
LL a, b, c;
LL s[N], f[N];
int q[N], h, t;
LL getf(int i, int j)
{
    return f[j] + a*(s[i]-s[j])*(s[i]-s[j]) + b*(s[i]-s[j]) + c;
}
LL getup(int i, int j)
{
    return (f[i] + a*s[i]*s[i] - b*s[i]) - (f[j] + a*s[j]*s[j] - b*s[j]) ;
}
LL getdown(int i, int j)
{
    return (s[i]-s[j]) << 1;
}
int main()
{
    cin >> n >> a >> b >> c;
    for (int i = 1; i <= n; i++)
    {
        cin >> s[i];
        s[i] += s[i-1];
    }
    q[h=t=0] = 0;
    for (int i = 1; i <= n; i++)
    {
        while (h < t && getup(q[h+1], q[h]) >= s[i] * getdown(q[h+1], q[h]) * a)
            ++h;
        f[i] = getf(i, q[h]);
        while (h < t && getup(i, q[t]) * getdown(q[t], q[t-1]) >= getup(q[t], q[t-1]) * getdown(i, q[t]))
            --t;
        q[++t] = i;
    }
    cout << f[n] << endl;
    return 0;
}

