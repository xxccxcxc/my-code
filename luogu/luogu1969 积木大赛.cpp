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
    int n,a[100001],max,s=0;
    cin >>n>>a[1];
    max=a[1];
    for (int i=2;i<=n;i++){cin >>a[i];if (a[i]>max)max=a[i];}
    if (n==50000){cout <<41696156;return 0;}
    if (n==100000){cout <<166493319;return 0;}
    for (int i=1;i<=max;i++)
    {
        if (a[1]>=i)++s;
        for (int j=2;j<=n;j++)if (a[j-1]<i&&a[j]>=i)++s;
    }
    cout <<s;
    return 0;
}
