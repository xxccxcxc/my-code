#include <algorithm>
#include <iostream>
#include <iomanip>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <string>
#include <cmath>
using namespace std;
int main()
{
    int n;
    double a[3][1001],t,max=0,min;
    cin >>n;
    for (int i=1;i<=n;i++)cin >>a[1][i]>>a[2][i];
    for (int j=2;j<=n;j++)
    {
        t=sqrt(abs((a[1][1]-a[1][j])*(a[1][1]-a[1][j])+(a[2][1]-a[2][j])*(a[2][1]-a[2][j])));
        if (t>max)max=t;
    }
    min=max;
    for (int i=1;i<=n;i++)
    {
        max=0;
        for (int j=1;j<=n;j++)
        {
            if (j==i)continue;
            t=sqrt(abs((a[1][i]-a[1][j])*(a[1][i]-a[1][j])+(a[2][i]-a[2][j])*(a[2][i]-a[2][j])));
            if (t>max)max=t;
        }
        if (max<min)min=max;
    }
    printf ("%0.4lf",3.1415926535*min*min);
    return 0;
}
