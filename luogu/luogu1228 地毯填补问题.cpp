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
int sx,sy,sr,s=1;
void fz(int x,int y,int tx,int ty,int t)
{
    if (t==1)return;
    t/=2;
    if (tx<x+t&&ty<y+t)
    {
        cout <<x+t<<' '<<y+t<<' '<<1<<endl;
        fz(x,y,tx,ty,t);
        fz(x,y+t,x+t-1,y+t,t);
        fz(x+t,y,x+t,y+t-1,t);
        fz(x+t,y+t,x+t,y+t,t);
    }
    else if (tx<x+t&&ty>=y+t)
    {
        cout <<x+t<<' '<<y+t-1<<' '<<2<<endl;
        fz(x,y,x+t-1,y+t-1,t);
        fz(x,y+t,tx,ty,t);
        fz(x+t,y,x+t,y+t-1,t);
        fz(x+t,y+t,x+t,y+t,t);
    }
    else if (tx>=x+t&&ty<y+t)
    {
        cout <<x+t-1<<' '<<y+t<<' '<<3<<endl;
        fz(x,y,x+t-1,y+t-1,t);
        fz(x,y+t,x+t-1,y+t,t);
        fz(x+t,y,tx,ty,t);
        fz(x+t,y+t,x+t,y+t,t);
    }
    else if (tx>=x+t&&ty>=y+t)
    {
        cout <<x+t-1<<' '<<y+t-1<<' '<<4<<endl;
        fz(x,y,x+t-1,y+t-1,t);
        fz(x,y+t,x+t-1,y+t,t);
        fz(x+t,y,x+t,y+t-1,t);
        fz(x+t,y+t,tx,ty,t);
    }
}
int main()
{
    cin >>sr>>sx>>sy;
    for (int i=1;i<=sr;i++)s*=2;
    fz(1,1,sx,sy,s);
    return 0;
}

