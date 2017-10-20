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
    int a[101],n,m,t;
    cin >>n>>m;
    for (int i=1;i<n;i++)a[i]=i+1;
    a[n]=1;t=n;
    for (int i=1;i<=n;i++)
    {
        for (int j=1;j<m;j++)t=a[t];
        cout <<a[t]<<' ';
        a[t]=a[a[t]];
    }
    return 0;
}
