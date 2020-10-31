#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
map<ll,int>mp;
ll n,m,t,ans=1<<29,a[40];
void dfs(ll x,ll now,ll up,ll cnt){
	if(x>up){
		if(now==m) ans=min(ans,cnt);
		if(up<n){
			t=mp[now];
			if(!t||t>cnt) mp[now]=cnt;
		}
		else{
			t=mp[m-now];
			if(!t) return;
			ans=min(ans,t+cnt);
		}
		return;
	}
	dfs(x+1,now,up,cnt);
	if(now+a[x]<=m) dfs(x+1,now+a[x],up,cnt+1);
}
int main()
{
	cin>>n>>m;
	for(int i=1;i<=n;++i) cin>>a[i];
	dfs(1,0,n/2,0);
	dfs(n/2+1,0,n,0);
	cout<<ans<<endl;
	return 0;
}
