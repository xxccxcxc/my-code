#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cstring>
#include <string>
#include <cmath>
#include <ctime>
#include <queue>
#include <stack>
using namespace std;
int n,m,a=0,c[31],tt;
string s;
void zh()
{
    tt=0;
    while (a>0)
    {
        c[++tt]=a%m;
        a/=m;
    }
    if (tt==0)++tt;
}
int main()
{
    cin >>n>>s>>m;
    for (int i=s.size()-1;i>=0;i--)
    {
        if (s[i]<='9')s[i]-='0';
        else s[i]=s[i]-'A'+10;
        a+=pow(double(n),double(s.size()-i-1))*s[i];
    }
    zh();
    for (int i=tt;i>=1;i--)
      if (c[i]<=9)cout <<c[i];
      else cout <<char(c[i]-10+'A');
    return 0;
}

