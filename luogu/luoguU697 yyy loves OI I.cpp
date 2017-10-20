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
    int n,b[101]={0};
    cin >>n;
    for (int i=1;i<=n;i++){cin >>b[i];b[i]*=i;cout <<b[i]-b[i-1]<<' ';}
    return 0;
}
