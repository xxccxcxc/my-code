#include <algorithm>
#include <iostream>
#include <iomanip>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <string>
#include <stack>
#include <queue>
#include <cmath>
#include <ctime>
using namespace std;
string s,s2,a[7],b[7],d[10001],d1[10001];
int tt=1,h,t,c[10001],h1,t1,c1[10001];
void bfs()
{
    h=h1=1;
    t=t1=1;
    c[1]=c1[1]=0;
    d[1]=s;d1[1]=s2;
    while (h<=t&&h1<=t1)
    {
        if (c[h]+c[h1]>10)break;
        for (int i=0;i<d[h].size();i++)
        {
            for (int j=1;j<=tt;j++)
            {
                if (a[j].size()>d[h].size()-i)continue;
                if (d[h].substr(i,a[j].size())==a[j])
                {
                    ++t;
                    c[t]=c[h]+1;
                    d[t]=d[h];
                    d[t].replace(i,a[j].size(),b[j]);
                    for (int k=1;k<=t1;k++)
                      if (d[t]==d1[k])
                        if (c[t]+c1[k]<=10)
                          {cout <<c[t]+c1[k];return;}
                }
            }
        }
        ++h;
        for (int i=0;i<d1[h1].size();i++)
        {
            for (int j=1;j<=tt;j++)
            {
                if (b[j].size()>d1[h1].size()-i)continue;
                if (d1[h1].substr(i,b[j].size())==b[j])
                {
                    ++t1;
                    c1[t1]=c1[h1]+1;
                    d1[t1]=d1[h1];
                    d1[t1].replace(i,b[j].size(),a[j]);
                    for (int k=1;k<=t;k++)
                      if (d1[t1]==d[k])
                        if (c1[t1]+c[k]<=10)
                          {cout <<c1[t1]+c[k];return;}
                }
            }
        }
        ++h1;
    }
    cout <<"NO ANSWER!";
}
int main()
{
    cin >>s>>s2;
    if (s==s2){cout <<0;return 0;}
    while (cin >>a[tt]>>b[tt])++tt;
    --tt;
    bfs();
    return 0;
}

