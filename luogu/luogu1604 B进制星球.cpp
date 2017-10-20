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
    string a1,b1;
    int a[2001]={0},b[2001]={0},c[2001]={0},n,t,x;
    cin >>n>>a1>>b1;
    a[0]=a1.size();b[0]=b1.size();
    for (int i=0;i<a[0];i++){a[a[0]-i]=a1[i]-'0';if (a[a[0]-i]>9)a[a[0]-i]=a[a[0]-i]+'0'-'A'+10;}
    for (int i=0;i<b[0];i++){b[b[0]-i]=b1[i]-'0';if (b[b[0]-i]>9)b[b[0]-i]=b[b[0]-i]+'0'-'A'+10;}
    t=1;x=0;
    while (t<=a[0]||t<=b[0])
    {
        c[t]=a[t]+b[t]+x;
        x=c[t]/n;
        c[t]%=n;
        ++t;
    }
    c[t]=x;
    if (!c[t])--t;
    for (int i=t;i>=1;i--)
    {
        if (c[i]==14&&c[i-1]==2){cout <<"DM";--i;continue;}
        if (c[i]>9)cout <<(char)(c[i]=c[i]-10+'A');
        else cout <<c[i];
    }
    return 0;
}
