#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <sstream>
#include <cstdio>
#include <string>
#include <vector>
#include <bitset>
#include <cmath>
#include <ctime>
#include <queue>
#include <stack>
#include <deque>
#include <map>
using namespace std;
bool pp;
void ying(int t)
{
    if (t==1)cout <<"xiaoa wins.";
    if (t==2)cout <<"uim wins.";
    if (t)pp=1;
}
int main()
{
    string a;
    int p[4][4];
    cin >>a;
    for (int i=0;i<a.size();i++)
    {
        int t=a[i]-'0';
        p[(t-1)/3+1][(t-1)%3+1]=i%2+1;
    }
    for (int i=1;i<=3;i++)
    {
        if (p[i][1]==p[i][2]&&p[i][1]==p[i][3])ying(p[i][1]);
        if (p[1][i]==p[2][i]&&p[1][i]==p[3][i])ying(p[1][i]);
    }
    if (p[1][1]==p[2][2]&&p[1][1]==p[3][3])ying(p[1][1]);
    if (p[1][3]==p[2][2]&&p[1][3]==p[3][1])ying(p[1][3]);
    if (!pp)cout <<"drew.";
    return 0;
}

