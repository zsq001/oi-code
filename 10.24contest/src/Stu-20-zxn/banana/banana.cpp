#include<bits/stdc++.h>
#define mod 1000000007
int n,k,ans,a[50],cnt,tot;
long long b[50];
void dfs(int now,long long mu){
	if(mu==k) {
		ans++;if(ans>=mod) ans-=mod;
		return ;
	}
	if(now==tot)return ;
	if(mu*b[now+1]<=k)dfs(now+1,mu*b[now+1]);
	dfs(now+1,mu);
}
int main(){
	int T;
	long long sum;
	freopen("banana.in","r",stdin);
	freopen("banana.out","w",stdout);
	scanf("%d",&T);
	while(T--){
		cnt=0;ans=0,sum=1,tot=0;
		scanf("%d%d",&n,&k);
		for(int i=1;i<=n;i++) {
			scanf("%d",a+i);
			if(a[i]==1)sum<<=1,sum%=mod;
			else if(a[i]){
				tot++;
				b[tot]=1ll*a[i];
			}
		}
		dfs(0,1);if(k==1&&ans==0) ans=1;
		printf("%d\n",(ans*sum)%mod);
	}
}
//3
//3 3
//1 1 3
//3 6
//2 3 6
//3 5
//1 5 1

