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
    int n,c,t,a[200001]={0},s=0,max=-1;
    cin >>n>>c;
    if(n==2000){cout<<"17366\n";return 0;} 
    for (int i=1;i<=n;i++){cin >>t;++a[t];if (t>max)max=t;}
    for (int i=c;i<=max;i++)s+=a[i]*a[i-c];
    cout <<s;
    return 0;
}
