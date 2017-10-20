#include <algorithm>
#include <iostream>
#include <iomanip>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <string>
#include <cmath>
#include <ctime>
using namespace std;
int main()
{
    char t;
    int z,y;
    z=y=0;
    while (1)
    {
        t=getchar();
        if (t=='@')break;
        if (t=='(')++z;
        if (t==')')++y;
    }
    if (z==y)cout <<"YES";
    else cout <<"NO";
    return 0;
}

