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
int main()
{
    int n,p[101]={0},ans=0,cut=0;
    string a[101],s,t;
    cin >>n;
    for (int i=1;i<=n;i++)cin >>a[i];
    getchar();
    getline (cin,s);
    for (int i=1;i<=n;i++)
      for (int j=0;j<a[i].size();j++)
        if (a[i][j]>='A'&&a[i][j]<='Z')
          a[i][j]=a[i][j]-'A'+'a';
    for (int i=0;i<s.size();i++)
      if (s[i]>='A'&&s[i]<='Z')
        s[i]=s[i]-'A'+'a';
    s+=".";
    for (int i=0;i<s.size();i++)
    {
        if (s[i]!='.'&&s[i]!=' '&&s[i]!=',')continue;
        if (s[i]=='.'&&(i==0||s[i-1]=='.'||s[i-1]==','||s[i-1]==' ')){for (int i=1;i<=n;i++)p[i]=0;}
        if (s[i]==0||s[i-1]=='.'||s[i-1]==','||s[i-1]==' '){cut=i+1;continue;}
        t=s.substr(cut,i-cut);
        cut=i+1;
        for (int j=1;j<=n;j++)
          if (a[j]==t)
          {
              if (p[j]==0)
              {
                  ++ans;
                  p[j]=1;
              }
              break;
          }
        if (s[i]=='.')for (int i=1;i<=n;i++)p[i]=0;
    }
    cout <<ans;
    return 0;
}

