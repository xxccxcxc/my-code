#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#define ll long long
using namespace std;
int i,j,k,m,n,s,t;
int read()
{
	int x=0;char ch=getchar();
	while (ch<'0'||ch>'9') ch=getchar();
	while (ch>='0'&&ch<='9') {x=x*10+ch-'0';ch=getchar();}
	return x;
}
int qpow(int x,int y)
{
	int mod=y+2,ans=1;
	while (y)
	{
		if (y&1) ans=(ll)ans*x%mod;
		x=(ll)x*x%mod;
		y>>=1;
	}
	return ans;
}
int a,b,inv,ans;
int main()
{
	a=read();
	b=read();
	if (a>b) swap(a,b);
	if (b<=0)
	{
	inv=qpow(a,b-2);
	for (i=1;i<=a*b;i++)
		if (i-inv*i%b*a<0) ans=max(ans,i);
	printf("%d\n",ans);
    } else
    {
	  cout<<((ll)a-1ll)*(ll)b-(ll)a<<endl;
    }
}

