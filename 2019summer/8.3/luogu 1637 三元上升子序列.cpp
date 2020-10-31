#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
struct P{
	int num,pos;
}a[30010];
ll n,now,ans,tree[30010],TREE[30010],b[30010];
bool cmp(P x,P y){return x.num<y.num;}
void add(int x){for(;x<=n;x+=x&-x) ++tree[x];}
void ADD(int x){for(;x<=n;x+=x&-x) ++TREE[x];}
ll query(int x){
	ll ret=0;
	for(;x;x-=x&-x) ret+=tree[x];
	return ret;
}
ll QUERY(int x){
	ll ret=0;
	for(;x;x-=x&-x) ret+=TREE[x];
	return ret;
}
int main()
{
	cin>>n;
	for(int i=1;i<=n;++i){
		cin>>a[i].num;
		a[i].pos=i;
	}
	sort(a+1,a+n+1,cmp);
	now=1;
	for(int i=1;i<=n;++i){
		if(a[i].num!=a[i-1].num)
			while(now<i)
				add(a[now++].pos);
		b[i]=query(a[i].pos-1);
	}
	now=n;
	for(int i=n;i>=1;--i){
		if(a[i].num!=a[i+1].num)
			while(now>i)
				ADD(a[now--].pos);
		ans+=b[i]*(QUERY(n)-QUERY(a[i].pos));
	}
	cout<<ans<<endl;
	return 0;
}
