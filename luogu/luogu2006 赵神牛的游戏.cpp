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
    int f,j,n,p=0,a,b,ds[30001],t=0;
    cin >>f>>j>>n;
    for (int i=1;i<=j;i++)
    {
        cin >>a>>b;
        if (!b)continue;
        if (!a){ds[++t]=i;p=1;continue;}
        if (b*(f/a)>=n){ds[++t]=i;p=1;}
    }
    if (p)for (int i=1;i<=t;i++)cout <<ds[i]<<' ';
    else cout <<-1;
    return 0;
}

