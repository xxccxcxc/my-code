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
    int p=1,d=0,x=101,m,l,a[26]={0};
    cin >>s;
    l=s.size();
    for (int i=0;i<l;i++)
      ++a[s[i]-'a'];
    for (int i=0;i<26;i++)
      if (a[i]>d)d=a[i];
      else if (a[i]<x&&a[i])x=a[i];
    m=d-x;
    for (int i=2;i<=sqrt(m);i++)
      if (m%i==0)
      {
          p=0;
          break;
      }
    if (m<=1)p=0;
    if (p)printf ("Lucky Word\n%d",m);
    else printf ("No Answer\n0");
    return 0;
}

