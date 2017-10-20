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
    string s1,s2;
    int a[50001]={0},b[50001]={0},c[50001]={0};
    cin >>s1>>s2;
    int la=s1.size(),lb=s2.size(),lc,x;
    for (int i=0;i<la;i++)a[la-i]=s1[i]-'0';
    for (int i=0;i<lb;i++)b[lb-i]=s2[i]-'0';
    for (int i=1;i<=la;i++)
    {
        x=0;
        for (int j=1;j<=lb;j++)
        {
            c[i+j-1]+=a[i]*b[j]+x;
            x=c[i+j-1]/10;
            c[i+j-1]%=10;
        }
        c[i+lb]=x;
    }
    lc=la+lb;
    while (c[lc]==0&&lc>1)--lc;
    for (int i=lc;i>=1;i--)cout <<c[i];
    return 0;
}
