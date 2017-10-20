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
int main()
{
    int i,t=1,p2[100]={0};
    string s,s1,s2;
    char p[100];
    for (int i='A';i<='Z';i++)
      p[i]='0';
    cin >>s1>>s2>>s;
    for (i=0;i<s1.size();i++)
    {
        if (p[s1[i]]!='0'&&s2[i]!=p[s1[i]])
          break;
        p[s1[i]]=s2[i];
    }
    for (int j='A';j<='Z';j++)
    {
        if (p[j]!='0')
          p2[p[j]]++;
        else
          t=0;
    }
    for (int j='A';j<='Z';j++)
      if (p2[j]>=2)
      {
          t=0;
          break;
      }
    if (i!=s1.size()||!t)
      cout <<"Failed";
    else
    {
        for (i=0;i<s.size();i++)
          cout <<p[s[i]];
    }
    return 0;
}
