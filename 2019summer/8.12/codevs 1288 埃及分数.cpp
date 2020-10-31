#include<bits/stdc++.h>
#define maxn 100010
#define inf 1<<29
#define ll long long
using namespace std;
ll ans[1010],rec[1010],FZ,FM,deep;
ll gcd(ll a,ll b){return b?gcd(b,a%b):a;}
void update(){
	if(ans[deep]>rec[deep])
		for(int i=1;i<=deep;++i) ans[i]=rec[i];
}
void dfs(int x,ll fz,ll fm){
	if(x==deep){
		rec[x]=fm;
		if(fz==1&&rec[x]>rec[x-1]) update();
		return;
	}
	for(ll i=max(rec[x-1]+1,fm/fz+1);i<(deep-x+1)*fm/fz;++i){
		ll xfz=fz*i-fm;
		ll xfm=fm*i;
		ll d=gcd(xfz,xfm);
		xfz/=d;
		xfm/=d;
		rec[x]=i;
		dfs(x+1,xfz,xfm);
	}
}
int main()
{
	cin>>FZ>>FM;
	ll d=gcd(FZ,FM);
	FZ/=d,FM/=d;
	deep=1;
	while(1){
		deep++;
		ans[deep]=inf;
		dfs(1,FZ,FM);
		if(ans[1]) break;
	}
	for(int i=1;i<=deep;++i) cout<<ans[i]<<" ";
    return 0;
}
