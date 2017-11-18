#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#define ll long long
using namespace std;
int i,j,k,m,n,s,t;
int read()
{
	int x=0,f=1;char ch=getchar();
	while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9') {x=x*10+ch-'0';ch=getchar();}
	return x*f;
}
int h,r,m1,first[10100],next[4010000],zhi[4010000],vis[10100];
ll dd;
struct data{
	int x,y,z;
}a[10100];
ll dis(const data &a,const data &b)
{
	return (a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y)+(a.z-b.z)*(a.z-b.z); 
}
void insert(int u,int v)
{
	//printf("!!!!%d %d\n",u,v); ///!!!!!!!!
	next[++m1]=first[u];
	first[u]=m1;
	zhi[m1]=v;
}
void dfs(int x)
{
	vis[x]=1;
	int k,v;
	for (k=first[x];k;k=next[k])
	{
		v=zhi[k];
		if (vis[v]) continue;
		dfs(v);
	}
}
int main()
{
	int T=read();
	while (T--)
	{
		for (i=1;i<=n+2;i++)
		  first[i]=0;
		m1=0;
	    n=read();
		h=read();
		r=read();
		for (i=1;i<=n;i++)
		{
			a[i].x=read();
			a[i].y=read();
			a[i].z=read();
			if (a[i].z<=r) insert(n+1,i);
			if (h-a[i].z<=r) insert(i,n+2);
		}
		dd=(ll)r*r*4ll;
		for (i=1;i<=n;i++)
		  for (j=i+1;j<=n;j++)
		  {
		  	if (dis(a[i],a[j])<=dd)
		  	{
		  		insert(i,j);
		  		insert(j,i);
		  	}
		  }
		for (i=1;i<=n+2;i++)
		  vis[i]=0;
		dfs(n+1);
		if (vis[n+2]) puts("Yes"); else puts("No");
	}
	return 0;
}

