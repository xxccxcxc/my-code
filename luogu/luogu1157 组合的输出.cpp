#include <algorithm>
#include <iostream>
#include <iomanip>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <string>
#include <cmath>
using namespace std;
int n,r,a[21];
void search(int i)
{
    for (int j=1;j<=n;j++)
    {
        if (j>a[i-1])
        {
            a[i]=j;
            if (i==r){for (int k=1;k<=r;k++)printf ("%3d",a[k]);cout <<endl;}
            else search (i+1);
        }
    }
}
int main()
{
    cin >>n>>r;
    search (1);
    return 0;
}
