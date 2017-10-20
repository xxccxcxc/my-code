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
priority_queue<int>a;
int k,m,t,tt=-1,p=0;
string b,ttt;
int main()
{
    cin >>k>>m;
    a.push(-1);
    for (int i=1;i<=k;i++)
    {
        t=a.top();
        a.push(2*t-1);
        a.push(4*t-5);
        t=-t;
        ttt="";
        while (t)
        {
            ttt+=(char)(t%10+48);
            t/=10;
        }
        for(int s1=ttt.size()-1;s1>=0;s1--)
        b+=ttt[s1];
        a.pop();
    }
    cout <<b<<endl;
    for (int i=1;i<=m;i++)
    {
        for (int j=0;j<b.size();j++)
          if (b[j]<b[j+1])
          {
              b.erase(j,1);
              break;
          }
    }
    while (b[0]==0){b.erase(0,1);}
    cout <<b;
    return 0;
}

