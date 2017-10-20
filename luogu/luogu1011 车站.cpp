#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cstring>
#include <string>
#include <cmath>
#include <ctime>
using namespace std;
int main()
{
    int a,n,m,x;
    int aa[21]={0},bb[21]={0},cc[21]={0};
    cin >>a>>n>>m>>x;
    for (int i=0;;i++)
    {
        aa[1]=a;aa[2]=i;
        bb[1]=0;bb[2]=i;
        cc[1]=a;cc[2]=a;
        for (int j=3;j<n;j++)
        {
            aa[j]=aa[j-2]+aa[j-1];
            bb[j]=aa[j-1];
            cc[j]=cc[j-1]+aa[j]-bb[j];
        }
        if (cc[n-1]==m){cout <<cc[x];break;}
    }
    return 0;
}

