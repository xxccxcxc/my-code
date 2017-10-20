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
    string a1;
    int n,a[2001]={0},b[2001]={0},j,k,x;
    cin >>n>>a1;
    a[0]=a1.size();
    for (int i=0;i<a[0];i++){if (a1[i]<='9')a[a[0]-i]=a1[i]-'0';else a[a[0]-i]=a1[i]+10-'A';}
    for (j=1;j<=a[0]/2;j++)if (a[j]!=a[a[0]-j+1])break;
    if (j>a[0]/2){cout <<"STEP="<<0;return 0;}
    for (k=1;k<=30;k++)
    {
        for (int i=1;i<=a[0];i++)b[i]=a[a[0]-i+1];
        x=0;
        for (int i=1;i<=a[0];i++)
        {
            a[i]+=b[i]+x;
            x=a[i]/n;
            a[i]%=n;
        }
        if (x)a[++a[0]]=x;
        for (j=1;j<=a[0]/2;j++)if (a[j]!=a[a[0]-j+1])break;
        if (j>a[0]/2){cout <<"STEP="<<k;break;}
    }
    if (k>30)cout <<"Impossible!";
    return 0;
}
