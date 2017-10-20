#include <algorithm>
#include <iostream>
#include <iomanip>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <string>
#include <queue>
#include <cmath>
#include <ctime>
using namespace std;
int main()
{
    int a[6][11],b[6],m,m1,s=0;
    for (int i=1;i<=5;i++)
      for (int j=1;j<=10;j++)
        cin >>a[i][j];
    for (int i=1;i<=5;i++)b[i]=1;
    for (int i=6;i<=25;i++)
    {
        m=200000000;
        m1=0;
        for (int i=1;i<=5;i++)
        {
            if (b[i]==10)continue;
            if (a[i][b[i]+1]-a[i][b[i]]<m)
            {
                m=a[i][b[i]+1]-a[i][b[i]];
                m1=i;
            }
        }
        ++b[m1];
    }
    for (int i=1;i<=5;i++)s+=a[i][b[i]];
    cout <<s<<endl;
    for (int i=1;i<=5;i++)cout <<b[i]<<' ';
    return 0;
}

