#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <string>

using namespace std;

const int N = 301000;
typedef long long ll;

struct Seg{
	ll key;
	int son[2],siz;
}num[N*30],val[N*30];
int root_num[N],len_num,tip;
int root_val[N],len_val,cnt_val[N];
ll key[N<<3];
int siz[N<<3],cnt[N]; 
int n,m,q,len;
void init(int,int,int);

ll getans_num(int,int,int,int);
//void add_num(int,int,int,int);
void insert(int,int,int,int,ll);
ll delet(int,int,int,int);
void add_val(int,int,int,int,ll);
ll getans_val(int,int,int,int);


int main(){
	scanf("%d%d%d",&n,&m,&q);
	for (int i = 1;i <= n;i++) {
		cnt[i] = m-1;
		root_num[i] = ++len_num;
		root_val[i] = ++len_val;
	}
	init(1,1,n+q);

	len = n;
	for (int i = 1;i <= q;i++){
		int x,y;tip = i;
		scanf("%d%d",&x,&y);
		if (y == m){
			ll ans = delet(1,1,n+q,x);
			len++;
			insert(1,1,n+q,len,ans);
			printf("%lld\n",ans);
		}
		else if (y <= cnt[x]){

			ll ans = getans_num(root_num[x],1,m,y);
			ans += (ll)m*(x-1);
//			ans += (ll)m*(x-1)+y;
//			add_num(root_num[x],1,m,y);
	
			cnt[x]--;
			printf("%lld\n",ans);
			len++;
			insert(1,1,n+q,len,ans);
			ll val = delet(1,1,n+q,x);
			cnt_val[x]++;
			add_val(root_val[x],1,q,cnt_val[x],val);
		}
		else{
			ll ans = getans_val(root_val[x],1,q,y-cnt[x]);//shunbian delete
			printf("%lld\n",ans);
			len++;
			insert(1,1,n+q,len,ans);
			ll val = delet(1,1,n+q,x);
			cnt_val[x]++;
			add_val(root_val[x],1,q,cnt_val[x],val);	
		}
	}
	return 0;
}
void init(int p,int l,int r){
	if (l == r) {
		siz[p] = 1;
		key[p] = (ll)l*m;
		return;
	}
	int mid = l + r >> 1;
	init(p<<1,l,mid);
	init(p<<1|1,mid+1,r);
	siz[p] = siz[p<<1]+siz[p<<1|1];
}
ll getans_num(int p,int l,int r,int x){
	if (l == r) {num[p].siz++;return l;}
	int mid = l + r >> 1;ll ans;
	int u = num[p].son[0],v = num[p].son[1],w = (mid-l+1)-num[u].siz;
	if (x <= w) {
		if (u == 0) {num[p].son[0] = ++len_num;u = len_num;}
		ans = getans_num(u,l,mid,x);
	}
	else {
		if (v == 0) {num[p].son[1] = ++len_num;v = len_num;}		
		ans = getans_num(v,mid+1,r,x-w);
	}
	num[p].siz++;
	return ans;
}
/*
void add_num(int p,int l,int r,int x){
	if (x <= l) {num[p].key++;return;}
	int mid = l + r >> 1;
	if (x <= mid){
		if (num[p].son[0] == 0)	num[p].son[0] = ++len_num;
		add_num(num[p].son[0],l,mid,x);
	}
	if (num[p].son[1] == 0)	num[p].son[1] = ++len_num;
	add_num(num[p].son[1],mid+1,r,x);
}
*/
void insert(int p,int l,int r,int x,ll y){
	if (l == r){
		key[p] = y;
		return;
	}
	int mid = l + r >> 1;
	if (x <= mid) insert(p<<1,l,mid,x,y);
	else insert(p<<1|1,mid+1,r,x,y);
}
ll delet(int p,int l,int r,int x){
	if (l == r){
		siz[p] = 0;
		return key[p];
	}
	int mid = l + r >> 1;ll ans = 0;
	int u = p<<1,v = p<<1|1;
	if (siz[u] >= x) ans = delet(u,l,mid,x);
	else ans = delet(v,mid+1,r,x-siz[u]);
	siz[p]--;
	return ans;
}
void add_val(int p,int l,int r,int x,ll y){
	if (l == r){
		val[p].key = y;
		val[p].siz = 1;
		return;
	}
	int mid = l + r >> 1;
	if (x <= mid){
		if (val[p].son[0] == 0) val[p].son[0] = ++len_val;
		add_val(val[p].son[0],l,mid,x,y);
	}
	else{
		if (val[p].son[1] == 0) val[p].son[1] = ++len_val;
		add_val(val[p].son[1],mid+1,r,x,y);		
	}
	val[p].siz++;
}
ll getans_val(int p,int l,int r,int x){
	if (l == r) {
		val[p].siz = 0;
		return val[p].key;
	}
	int mid = l + r >> 1;ll ans = 0;
	int u = val[p].son[0],v = val[p].son[1];
	if (val[u].siz >= x) ans = getans_val(u,l,mid,x);
	else ans = getans_val(v,mid+1,r,x-val[u].siz); 
	val[p].siz--;
	return ans;
}


