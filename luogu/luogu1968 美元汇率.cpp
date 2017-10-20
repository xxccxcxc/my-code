#include <algorithm>
#include <iostream>
#include <iomanip>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <string>
#include <queue>
#include <cmath>
#include <ctime>
using namespace std;
int main()
{
    int n;
    double a[101],mk[101]={0},my[101]={0};
    cin >>n;
    for (int i=1;i<=n;i++)cin >>a[i];
    my[0]=100;
    for (int i=1;i<=n;i++)
    {
        mk[i]=mk[i-1];my[i]=my[i-1];
        for (int j=1;j<=i;j++)
        {
            if (mk[j]*(100.0/a[j])>my[i])my[i]=mk[j]*(100.0/a[j]);
            if (my[j]*(a[j]/100.0)>mk[i])mk[i]=my[j]*(a[j]/100.0);
        }
    }
    printf ("%0.2lf",my[n]);
    return 0;
}

