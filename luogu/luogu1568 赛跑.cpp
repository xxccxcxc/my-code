#include <algorithm>
#include <iostream>
#include <iomanip>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <string>
#include <cmath>
using namespace std;
int sd1[1001],sj1[1001],sd2[1001],sj2[1001],n,m,s,ans,lc1,lc2,i1=1,i2=1,p=-1;
int main()
{
    cin >>n>>m;
    for (int i=1;i<=n;i++){cin >>sd1[i]>>sj1[i];s+=sj1[i];}
    for (int i=1;i<=m;i++)cin >>sd2[i]>>sj2[i];
    for (int i=1;i<=s;i++)
    {
        if (!sj1[i1])++i1;if(!sj2[i2])++i2;
        lc1+=sd1[i1];lc2+=sd2[i2];
        --sj1[i1];--sj2[i2];
        if (lc1>lc2&&p!=0){p=0;ans++;}
        if (lc2>lc1&&p!=1){p=1;ans++;}
    }
    if (ans==0)cout <<0;
    else cout <<ans-1;
    return 0;
}
