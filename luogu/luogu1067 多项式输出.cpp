#include <algorithm>
#include <iostream>
#include <iomanip>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <string>
#include <cmath>
#include <ctime>
using namespace std;
int main()
{
    int n,t;
    cin >>n;
    for (int i=1;i<=n+1;i++)
    {
        cin >>t;
        if (!t)continue;
        if (abs(t)!=1||i>n)
        {
            if (t>0&&i!=1)cout <<'+';
            cout <<t;
        }
        else if (t==1){if (i!=1)cout <<'+';}
        else cout <<'-';
        if (i<=n){cout <<'x';if (i!=n)cout <<'^'<<n-i+1;}
    }
    return 0;
}
