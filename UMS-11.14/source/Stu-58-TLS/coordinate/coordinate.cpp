#include<cstdio>
#include<string>
#include<cmath>
#include<algorithm>
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll mod=1e9+7;
#define maxn 1000010

ll n,ans,vis[5010][5010];
int fx[4]={0,-1,1};
int fy[4]={1,0,0};

void dfs(int step,int x,int y){
	if(x<-step||x>step||y<-step||y>step) return ;
	if(step<0) return ;
	if(vis[x][y]) return ;
	vis[0][0]=1;
	for(int i=0;i<=2;++i){
		int xx=x+fx[i],yy=y+fy[i];
		if(!vis[xx][yy]&&step){
			vis[xx][yy]=1;step--;
			dfs(step,xx,yy);
		}
		else {
			step++;
			vis[xx][yy]=0;
		}
		if(step==0){
			ans++;ans%=mod;
		}
	}
}

int main(){
	freopen("coordinate.in","r",stdin);
	freopen("coordinate.out","w",stdout);
	memset(vis,0,sizeof(vis));
	scanf("%d",&n);
	dfs(n,0,0);
	printf("%lld",ans%mod);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
