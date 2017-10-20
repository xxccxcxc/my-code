#include <iostream>
using namespace std;
int main()
{
    int s=0,n,max=-1,t,t1,t2,t5;
    char t3,t4;
    string a,m;
    cin >>n;
    for (int i=1;i<=n;i++)
    {
        cin >>a>>t1>>t2>>t3>>t4>>t5;
        t=0;
        if (t1>80&&t5>=1)t+=8000;
        if (t1>85&&t2>80)t+=4000;
        if (t1>90)t+=2000;
        if (t1>85&&t4=='Y')t+=1000;
        if (t2>80&&t3=='Y')t+=850;
        if (t>max){max=t;m=a;}
        s+=t;
    }
    cout <<m<<endl<<max<<endl<<s;    return 0;
}
