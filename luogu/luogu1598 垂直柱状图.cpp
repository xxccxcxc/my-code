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
    string s;
    int a[26]={0},m=0;
    for (int i=1;i<=4;i++)
    {
        getline(cin,s);
        for (int j=0;j<=s.size();j++)
          if (s[j]>='A'&&s[j]<='Z')
            a[s[j]-'A']++;
    }
    for (int i=0;i<26;i++)
      if (a[i]>m)
        m=a[i];
    for (int i=m;i>=1;i--)
    {
        for (int j=0;j<25;j++)
        {
          if (a[j]>=i)
            cout <<'*'<<' ';
          else
            cout <<"  ";
        }
        if (a[25]>=i)
            cout <<'*';
          else
            cout <<' ';
        cout <<endl;
    }
    for (int i='A';i<'Z';i++)
      cout <<(char)i<<' ';
    cout <<'Z';
    return 0;
}
