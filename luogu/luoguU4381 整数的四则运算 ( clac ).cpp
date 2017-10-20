#include <iostream>
#include <cstdio>
using namespace std;
int main()
{
    long long a,b;
    cin >>a>>b;
    cout <<a<<'+'<<b<<'='<<a+b<<endl;
    cout <<a<<'-'<<b<<'='<<a-b<<endl;
    cout <<a<<'*'<<b<<'='<<a*b<<endl;
    cout <<a<<'/'<<b<<'='<<a/b;
    if (a%b)printf ("...%d",a%b);
    return 0;
}

