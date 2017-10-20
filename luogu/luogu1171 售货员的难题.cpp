#include <cstdio> 
int n,a[41][41],m=100000000;  
bool p[41];  
void dfs(int t,int l,int lc)  
{  
    if (lc>=m)return;  
    if (t==n){if (lc+a[l][1]<m)m=lc+a[l][1];return;}  
    for (int i=2;i<=n;i++)  
    {  
        if (!p[i]&&lc+a[l][i]+n-t<m)  
        {  
            p[i]=true;  
            dfs(t+1,i,lc+a[l][i]);  
            p[i]=false;  
        }  
    }  
}  
int main()  
{  
    scanf ("%d",&n);  
    for (int i=1;i<=n;i++)  
      for (int j=1;j<=n;j++)  
        scanf ("%d",&a[i][j]);
    dfs (1,1,0);  
    printf ("%d",m);  
    return 0;  
} 

