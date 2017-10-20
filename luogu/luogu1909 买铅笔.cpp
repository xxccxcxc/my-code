#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <algorithm>
#include <cstring>
#include <utility>
#include <map>
#include <stack>
#include <set>
#include <vector>
#include <queue>
using namespace std;
int main()
{
    int n,a,qa,b,qb,c,qc,sa,sb,sc;
    cin >>n>>a>>qa>>b>>qb>>c>>qc;
    sa=(n+a-1)/a*qa;
    sb=(n+b-1)/b*qb;
    sc=(n+c-1)/c*qc;
    cout <<min(sa,min(sb,sc))<<endl;
    return 0;
}
