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
void zk(char a,char b,int p1,int p2,int p3)
{
    char t;
    if (p3==1)
    {
        for (int i=a+1;i<b;i++)
        {
            if (p1==3)
              t='*';
            else
            {
                t=i;
                if (p1==2&&i>='a')
                  t-='a'-'A';
            }
            for (int j=1;j<=p2;j++)
              cout <<t;
        }
    }
    else
    {
        for (int i=b-1;i>a;i--)
        {
            if (p1==3)
              t='*';
            else
            {
                t=i;
                if (p1==2&&i>='a')
                  t-='a'-'A';
            }
            for (int j=1;j<=p2;j++)
              cout <<t;
        }
    }
}
bool pd(char a,char b)
{
    int p1,p2;
    if (a>=b||a=='-'||b=='-')
      return false;
    p1=a>='a'&&a<='z'?1:0;
    p2=b>='a'&&b<='z'?1:0;
    if (p1!=p2)
      return false;
    else
      return true;
}
int main()
{
    int p1,p2,p3;
    string a;
    cin >>p1>>p2>>p3>>a;
    cout <<a[0];
    for (int i=1;i<a.size()-1;i++)
    {
        if (a[i]=='-'&&pd(a[i-1],a[i+1]))
        {
            zk(a[i-1],a[i+1],p1,p2,p3);
            continue;
        }
        cout <<a[i];
    }
    cout <<a[a.size()-1];
    return 0;
}
