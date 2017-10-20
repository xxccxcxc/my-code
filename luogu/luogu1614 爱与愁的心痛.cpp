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
    int n,m,a[3001],min=0,s;
    cin >>n>>m;
    for (int i=1;i<=n;i++)cin >>a[i];
    for (int i=1;i<=m;i++)min+=a[i];
    for (int i=2;i<=n-m+1;i++)
    {
        s=0;
        for (int j=0;j<m;j++)s+=a[i+j];
        if (s<min)min=s;
    }
    cout <<min;
    return 0;
}

