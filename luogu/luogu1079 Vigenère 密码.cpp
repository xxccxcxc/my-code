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
char zh(char c,char s)
{
    bool dx=s>'Z'?0:1;
    s-=c;
    if (dx)
    {
      if (s<'A')
        s+=26;
    }
    else
      if (s<'a')
        s+=26;
    return s;
}
int main()
{
    int a[101],t=0;
    char c[101],s[1001];
    cin >>c>>s;
    strlwr(c);
    for (int i=0;i<strlen(c);i++)
      a[i]=c[i]-'a';
    for (int i=0,t=0;i<strlen(s);i++,t++)
    {
        if (t==strlen(c))
          t=0;
        cout <<zh(a[t],s[i]);
    }
    return 0;
}
