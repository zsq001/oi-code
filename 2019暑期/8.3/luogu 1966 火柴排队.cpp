#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
#include<cmath>
#define eps 1e-8
#define ll long long
#define mod 99999997
using namespace std;
struct M{
	ll val,rk,pos;
}a[100010],b[100010];
int v[100010],tree[100010],n;
ll ans;
bool cmp1(M x,M y){return x.val<y.val;}
bool cmp2(M x,M y){return x.pos<y.pos;}
void insert(int x){for(;x<=n;x+=x&-x) tree[x]++;}
int query(int x){
	int ret=0;
	for(;x;x-=x&-x) ret+=tree[x];
	return ret;
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;++i){
		
		scanf("%d",&a[i].val);
		a[i].rk=i;
	}
	for(int i=1;i<=n;++i){
		scanf("%d",&b[i].val);
		b[i].rk=i;
	}
	sort(a+1,a+n+1,cmp1);
	sort(b+1,b+n+1,cmp1);
	for(int i=1;i<=n;++i) a[i].pos=i,b[i].pos=i;
	sort(a+1,a+n+1,cmp2);
	sort(b+1,b+n+1,cmp2);
	for(int i=1;i<=n;++i) v[b[i].rk]=a[i].rk;
	for(int i=1;i<=n;++i){
		ans+=query(n)-query(v[i]);
		insert(v[i]);
	}
	printf("%d",ans%mod);
	return 0;
}
