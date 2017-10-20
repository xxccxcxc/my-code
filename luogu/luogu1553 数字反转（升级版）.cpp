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
int t;
int lx(string a)
{
    for (int i=0;i<a.size();i++)
    {
        if (a[i]=='.')
        {t=i;return 1;}
        if (a[i]=='/')
        {t=i;return 2;}
        if (a[i]=='%')
        {t=i;return 3;}
    }
    return 0;
}
void fz(string a)
{
    for (int i=a.size()-1;i>=0;i--)
      if (a[i]=='0'&&i)
        a.erase(i,1);
      else
        break;
    for (int i=a.size()-1;i>=0;i--)
      cout <<a[i];
}
void xs(string a)
{
    fz(a.substr(0,t));
    string s=a.substr(t+1,a.size()-(t+1));
    cout <<'.';
    for (int i=0;i<s.size();i++)
      if (s[i]=='0'&&i<s.size()-1)
      {s.erase(i,1);--i;}
      else
        break;
    for (int i=s.size()-1;i>=0;i--)
      cout <<s[i];
}
void fs(string a)
{
    string a1=a.substr(0,t),a2=a.substr(t+1,a.size()-(t+1));
    fz(a1);
    cout <<'/';
    fz(a2);
}
void bfs(string a)
{
    fz(a.substr(0,a.size()-1));
    cout <<'%';
}
int main()
{
    string s;
    int t;
    cin >>s;
    t=lx(s);
    switch(t)
    {
        case 0:fz(s);break;
        case 1:xs(s);break;
        case 2:fs(s);break;
        case 3:bfs(s);break;
        default:cout <<"error";
    }
    return 0;
}
