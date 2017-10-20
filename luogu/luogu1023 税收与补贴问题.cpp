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
    int yq,jg[11],xl[11],sr=0,p=-1,t,maxx,n=0,tt,tyq,js;
    cin >>yq;
    do
    {
        cin >>jg[++n]>>xl[n];
    }while (jg[n]!=-1&&xl[n]!=-1);
    --n;
    cin >>js;
    for (int i=0;i<=1000;i++)
    {
        p*=-1;
        t=i*p/2;
        maxx=t*xl[1];
        for (int j=1;j<n;j++)
        {
            for (int k=jg[j]+1;k<=jg[j+1];k++)
            {
                tt=(xl[j]+(xl[j+1]-xl[j])/(jg[j+1]-jg[j])*(k-jg[j]))*(k-jg[1]+t);
                maxx=max(maxx,tt);
                if (k==yq)tyq=tt;
            }
        }
        for (int jgg=jg[n]+1,xll=xl[n]-js;xll>0;jgg++,xll-=js)
        {
            tt=(jgg-jg[1]+t)*xll;
            maxx=max(maxx,tt);
            if (jgg==yq)tyq=tt;
        }
        if (tyq==maxx){cout <<t;return 0;}
    }
    cout <<"NO SOLUTION";
    return 0;
}

