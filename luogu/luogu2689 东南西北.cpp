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
int main()
{
    int a,b,c,d,m,t1=0,t2=0;
    cin >>a>>b>>c>>d>>m;
    for (int i=1;i<=m;i++)
    {
        char r;
        cin >>r;
        if (a<c&&r=='N')++t1;
        if (a>c&&r=='S')++t1;
        if (b<d&&r=='E')++t2;
        if (b>d&&r=='W')++t2;
    }
    if (t1>=abs(a-c)&&t2>=abs(b-d))cout <<abs(a-c)+abs(b-d);
    else cout <<-1;
    return 0;
}

