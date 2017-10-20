#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cstring>
#include <string>
#include <cmath>
#include <ctime>
using namespace std;
string a,b;
void dg(int l1,int r1,int l2,int r2)
{
    int t=a.find(b[r2]);
    //cout <<l1<<' '<<r1<<' '<<l2<<' '<<r2<<' '<<t;
    cout <<b[r2];
    if (t>l1)dg(l1,t-1,l2,l2+t-l1-1);
    if (t<r1)dg(t+1,r1,l2+t-l1,r2-1);
}
int main()
{
    cin >>a>>b;
    dg(0,a.size()-1,0,b.size()-1);
    return 0;
}
//BADC
//BDCA

