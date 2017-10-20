#include <iostream>
const int p=65536;
using namespace std;
int main()
{
    long long n;
    cin >>n;
    cout <<(n%p)*p+(n/p);
    return 0;
}

