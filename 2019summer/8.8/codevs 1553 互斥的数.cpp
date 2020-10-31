#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
#define ll long long
#define mod 100003
using namespace std;
ll n,p,hl[mod+7],cnt,ans,a[mod+7];
struct Num{
	ll v,ne;
}e[mod+7];
void add(ll key,ll v)
{
	e[++cnt].v=v;
	e[cnt].ne=hl[key];
	hl[key]=cnt;
}
bool find(ll key,ll v)
{
	for(ll i=hl[key];i;i=e[i].ne) if(e[i].v==v) return true;
	return false;
}
int main()
{
	scanf("%d%d",&n,&p);
	for(ll i=1;i<=n;++i) scanf("%d",&a[i]);
	sort(a+1,a+n+1);
	for(ll i=1;i<=n;++i){
		if(find(a[i]%mod,a[i])) continue;
		ll v=a[i]*p;
		if(v<=1e9) add(v%mod,v);
		++ans;
	}
	cout<<ans;
	return 0;
}
