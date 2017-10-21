#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <sstream>
#include <utility>
#include <cstdio>
#include <string>
#include <vector>
#include <cmath>
#include <ctime>
#include <queue>
#include <stack>
#include <deque>
#include <set>
#include <map>
#define mo 1000000007
using namespace std;
int main()
{
    //freopen ("test.txt","r",stdin);
    //freopen ("output.txt","w",stdout);
    int n=0;
    long long f[11]={0};
    char c[500005]="",ch;
    while (cin >>ch)
    {
        if (ch<'a')ch+='a'-'A';
        if (ch!='h'&&ch!='e'&&ch!='l'&&ch!='o'&&ch!='w'&&ch!='r'&&ch!='d')continue;
        c[++n]=ch;
    }
    //for (int i=1;i<=n;i++)cout <<c[i];cout <<endl;
    for (int i=1;i<=n;i++)
    {
        if (c[i]=='h')++f[1];
        else if (c[i]=='e')f[2]=(f[2]+f[1])%mo;
        else if (c[i]=='l')
        {
            f[9]=(f[9]+f[8])%mo;
            f[4]=(f[4]+f[3])%mo;
            f[3]=(f[3]+f[2])%mo;
        }
        else if (c[i]=='o')
        {
            f[7]=(f[7]+f[6])%mo;
            f[5]=(f[5]+f[4])%mo;
        }
        else if (c[i]=='w')f[6]=(f[6]+f[5])%mo;
        else if (c[i]=='r')f[8]=(f[8]+f[7])%mo;
        else if (c[i]=='d')f[10]=(f[10]+f[9])%mo;
        //cout <<i<<" ¡¡";for (int i=1;i<=10;i++)cout <<f[i]<<' ';cout <<endl; 
    }
    cout <<f[10];
     return 0;
}

