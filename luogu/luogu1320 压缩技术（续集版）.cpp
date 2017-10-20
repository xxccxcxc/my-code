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
    string s[201];
    int a[40001]={0};
    cin >>s[1];
    int n=s[1].size(),t=1;
    bool p=0;
    for (int i=2;i<=n;i++)
      cin >>s[i];
    for (int i=1;i<=n;i++)
      for (int j=0;j<n;j++)
      {
          if (s[i][j]-'0'!=p)
          {
              ++t;
              p=p==0;
          }
          ++a[t];
      }
    cout <<n;
    for (int i=1;i<=t;i++)
      cout <<' '<<a[i];
    return 0;
}
