#include <algorithm>
#include <iostream>
#include <iomanip>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <string>
#include <cmath>
using namespace std;
int n,a[11],p,ans;
void print()
{
    for (int i=1;i<=10;i++)cout <<a[i]<<' ';
    cout <<endl;
}
void dfs(int t,int s)
{
    for (int i=1;i<=3;i++)
    {
        if (s-i>=10-t&&s-i<=(10-t)*3)
        {
            if (p)a[t]=i;
            if (t==10)
            if (p)print ();
            else ++ans;
            else dfs (t+1,s-i);
        }
    }
}
int main()
{
    cin >>n;
    dfs (1,n);
    cout <<ans<<endl;
    p=1;
    dfs (1,n);
    return 0;
}

