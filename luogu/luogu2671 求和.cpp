#include<cmath>
#include<ctime>
#include<stack>
#include<queue>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
struct sum{
    int a,b,c;
}s[100001];
bool cmp(sum s1,sum s2)
{
    return s1.c<s2.c;
}
int n,m,ans;
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
    {
        s[i].a=i;
        scanf("%d",&s[i].b);
        s[i].b%=10007;
    }
    for(int i=1;i<=n;i++)
        scanf("%d",&s[i].c);
    sort(s+1,s+n+1,cmp);
    for(int i=1;i<=n;i++)
        for(int j=i+1;j<=n;j++)
        {
            if(s[i].c!=s[j].c)break;
            if(s[i].a%2==s[j].a%2)
                ans=((((s[i].a+s[j].a)%10007)*((s[i].b+s[j].b)%10007))%10007+ans)%10007;
        }
    cout<<ans<<endl;
    return 0;
}


