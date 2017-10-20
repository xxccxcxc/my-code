#include <algorithm>
#include <iostream>
#include <iomanip>
#include <climits>
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
    string s1,s2;
    int sa,sb,a[10001]={0},b[10001]={0},c[10001]={0},p=0,t;
    cin >>s1>>s2;
    if (s1.size()<s2.size()||(s1.size()==s2.size()&&s1<s2)){p=1;swap(s1,s2);}
    sa=s1.size();sb=s2.size();
    for (int i=1;i<=sa;i++)a[i]=s1[sa-i]-'0';
    for (int i=1;i<=sb;i++)b[i]=s2[sb-i]-'0';
    for (int i=1;i<=sa;i++)
    {
        if (a[i]<b[i]){--a[i+1];a[i]+=10;}
        c[i]=a[i]-b[i];
    }
    t=sa;
    while (c[t]==0&&t>1)--t;
    if (p==1&&(t!=1||c[1]!=0))cout <<'-';
    for (int i=t;i>=1;i--)cout <<c[i];
    return 0;
}

