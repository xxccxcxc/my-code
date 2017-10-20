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
int main()
{
    int n;
    char s[11];
    bool p=0;
    cin >>n;
    if (n<0){n=-n;p=1;}
    sprintf (s,"%d",n);
    for (int i=0;i<=strlen(s)/2-1;i++)swap(s[i],s[strlen(s)-i-1]);
    sscanf (s,"%d",&n);
    if (p)n=-n;
    cout <<n;
    return 0;
}

