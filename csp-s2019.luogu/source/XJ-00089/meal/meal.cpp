#include<cstdio>
#include<algorithm>
#include<cstdlib>
#include<cmath>
#include<stdio.h>
#define ll long long
using namespace std;
ll mod=998244353;
ll meal[110][2010];
int vis[2010];
int n,m;
ll ans=0;

void solve(int d,int nowa,int tar,int anst){
	for(int j=nowa+1;j<=n-(tar-d);j++){
		for(int i=1;i<=m;i++){
		
			if(vis[i]+1>tar/2||meal[j][i]==0)continue;
		
			if(d==tar)ans=(ans+((anst*meal[j][i])%mod))%mod;
			else{
				vis[i]++;
				solve(d+1,j,tar,(anst*meal[j][i])%mod);
				vis[i]--;
			}
		}
	} 
	
}

int main(){
	freopen("meal.in","r",stdin);
	freopen("meal.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			scanf("%d",&meal[i][j]);
		}
	}
	for(int i=2;i<=n;i++){
		solve(1,0,i,1);
	}
	printf("%lld",ans);
	return 0;
}
