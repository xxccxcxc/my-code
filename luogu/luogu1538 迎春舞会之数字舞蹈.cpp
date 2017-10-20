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
int a[10][5],ss,n,c,g,tt,ttt;
string s;
void dh(int t)
{
    for (int i=0;i<ss;i++)
    {
        tt=s[i]-'0';
        cout <<' ';
        for (int j=1;j<=n;j++)
          if (a[tt][t])cout <<'-';
          else cout <<' ';
        cout <<"  ";
    }
    cout <<endl;
}
void ds(int t)
{
    for (int i=1;i<=n;i++)
    {
        for (int j=0;j<=ss;j++)
        {
            tt=s[j]-'0';
            if (a[tt][t]==1||a[tt][t]==3)cout <<'|';
            else cout <<' ';
            for (int k=1;k<=n;k++)cout <<' ';
            if (a[tt][t]==2||a[tt][t]==3)cout <<'|';
            else cout <<' ';
            cout <<' ';
        }
        cout <<endl;
    }
}
int main()
{
    a[1][1]=0;
    a[1][2]=2;
    a[1][3]=0;
    a[1][4]=2;
    a[1][5]=0;
    a[2][1]=1;
    a[2][2]=2;
    a[2][3]=1;
    a[2][4]=1;
    a[2][5]=1;
    a[3][1]=1;
    a[3][2]=2;
    a[3][3]=1;
    a[3][4]=2;
    a[3][5]=1;
    a[4][1]=0;
    a[4][2]=3;
    a[4][3]=1;
    a[4][4]=2;
    a[4][5]=0;
    a[5][1]=1;
    a[5][2]=1;
    a[5][3]=1;
    a[5][4]=2;
    a[5][5]=1;
    a[6][1]=1;
    a[6][2]=1;
    a[6][3]=1;
    a[6][4]=3;
    a[6][5]=1;
    a[7][1]=1;
    a[7][2]=2;
    a[7][3]=0;
    a[7][4]=2;
    a[7][5]=0;
    a[8][1]=1;
    a[8][2]=3;
    a[8][3]=1;
    a[8][4]=3;
    a[8][5]=1;
    a[9][1]=1;
    a[9][2]=3;
    a[9][3]=1;
    a[9][4]=2;
    a[9][5]=1;
    a[0][1]=1;
    a[0][2]=3;
    a[0][3]=0;
    a[0][4]=3;
    a[0][5]=1;
    cin >>n>>s;
    ss=s.size();
    dh(1);
    ds(2);
    dh(3);
    ds(4);
    dh(5);
    return 0;
}

