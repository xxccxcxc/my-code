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
    int n,m,t1,t2,a[100001]={0},s;
    char p;
    cin >>n>>m;
    for (int i=1;i<=m;i++)
    {
        cin >>p>>t1>>t2;
        if (p=='x')a[t1]+=t2;
        else
        {
            s=0;
            for (int j=t1;j<=t2;j++)s+=a[j];
            cout <<s<<endl;
        }
    }
    return 0;
}

