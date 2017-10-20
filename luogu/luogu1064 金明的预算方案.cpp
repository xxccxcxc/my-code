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
    int m,n,zy,tt,w[61]={0},c[61]={0},fj[61][3]={0},f[3201]={0};
    cin >>m>>n;
    m/=10;
    for (int i=1;i<=n;i++)
    {
        cin >>w[i]>>zy>>tt;
        w[i]/=10;
        c[i]=w[i]*zy;
        if (tt!=0){fj[tt][++fj[tt][0]]=i;fj[i][0]=-1;}
    }
    for (int i=1;i<=n;i++)
    {
        if (fj[i][0]!=-1)
        {
            for (int j=m;j>=1;j--)
            {
                if (j>=w[i])f[j]=max(f[j],f[j-w[i]]+c[i]);
                if (j>=w[i]+w[fj[i][1]])f[j]=max(f[j],f[j-w[i]-w[fj[i][1]]]+c[i]+c[fj[i][1]]);
                if (j>=w[i]+w[fj[i][2]])f[j]=max(f[j],f[j-w[i]-w[fj[i][2]]]+c[i]+c[fj[i][2]]);
                if (j>=w[i]+w[fj[i][1]]+w[fj[i][2]])f[j]=max(f[j],f[j-w[i]-w[fj[i][1]]-w[fj[i][2]]]+c[i]+c[fj[i][1]]+c[fj[i][2]]);
            }
        }
    }
    cout <<f[m]*10;
    return 0;
}

