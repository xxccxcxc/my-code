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
int a=0,b=0,c=0;
void bz(char a1,char a2)
{
    int s;
    if (a2>='0'&&a2<='9')
      s=a2-'0';
    else
    {
        if (a2=='a')
          s=a;
        if (a2=='b')
          s=b;
        if (a2=='c')
          s=c;
    }
    if (a1=='a')
      a=s;
    if (a1=='b')
      b=s;
    if (a1=='c')
      c=s;
}
int main()
{
    string s;
    cin >>s;
    for (int i=0;i<s.size();i++)
      if (s[i+1]==':')
        bz(s[i],s[i+3]);
    cout <<a<<' '<<b<<' '<<c;    return 0;
}

