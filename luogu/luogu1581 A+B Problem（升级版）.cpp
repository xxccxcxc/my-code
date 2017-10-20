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
    string s;
    int a[6]={0},b[6]={0},c[7]={0},x=0,jw[7]={0,2,3,5,7,11,100},t,w,p=0,p1=0,p2=0;
    cin >>s;
    for (int i=0;i<s.size();i++)
      if (s[i]=='+'){t=i;break;}
    if (s[0]=='1'&&s[1]=='0')p1=1;
    if (s[t+1]=='1'&&s[t+2]=='0')p2=1;
    for (int i=0;i<s.size();i++)
    {
        if (s[i]==',')
        {
            s.erase(i,1);
            --i;
        }
    }
    w=s.size();
    for (int i=0;i<w;i++)
      if (s[i]=='+'){t=i;break;}
    for (int i=1;i<=t;i++)a[i]=s[t-i]-'0';
    for (int i=1;i<w-t;i++)b[i]=s[w-i]-'0';
    if (p1)a[5]=10;
    if (p2)b[5]=10;
    a[0]=t;b[0]=w-t-1;
    for (int i=1;i<=5;i++)
    {
        c[i]=a[i]+b[i]+x;
        x=c[i]/jw[i];
        c[i]%=jw[i];
    }
    c[6]=x;
    for (int i=6;i>=1;i--)
    {
        if (c[i]==0&&!p)continue;
        if (p)cout <<',';
        else p=1;
        if (c[i]>9)cout <<c[i]-10+'A';
        else cout <<c[i];
    }
    return 0;
}
