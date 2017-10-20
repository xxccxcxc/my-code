#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cstring>
#include <string>
#include <cmath>
#include <ctime>
#include <queue>
#include <stack>
using namespace std;
bool p[5][5]={
{0,0,1,1,0},
{1,0,0,1,0},
{0,1,0,0,1},
{0,0,1,0,1},
{1,1,0,0,0},
};
int main()
{
    int n,na,nb,a[201]={0},b[201]={0},aa=0,bb=0,sa=0,sb=0;
    cin >>n>>na>>nb;
    for (int i=1;i<=na;i++)cin >>a[i];
    for (int i=1;i<=nb;i++)cin >>b[i];
    for (int i=1;i<=n;i++)
    {
        ++aa;++bb;
        if (aa>na)aa=1;
        if (bb>nb)bb=1;
        sa+=p[a[aa]][b[bb]];
        sb+=p[b[bb]][a[aa]];
    }
    cout <<sa<<' '<<sb;
    return 0;
}

