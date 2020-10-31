#include<cstdio>
#include<algorithm>
#include<cstring>
#include<iostream>
#define N 200100
#define M 5050
using namespace std ;
struct edge{
	double v,next,u,val;
}e[N];
int cnt,l,p,n;
int head[N],f[N],rd[N],vis[N];
double ans;
void add(int u,double v,double val){
	e[++cnt].v=v;
	e[cnt].u=u;
	e[cnt].val=val;
	e[cnt].next=head[u];
	head[u]=cnt;
}
void dfs(int u,int x,double sum,double cost){
	if(x==u and cost!=0){
		ans=max(ans,(cost/sum)*1.0);
		return ;
	}
	for(int i=head[x];i;i=e[i].next){
		int v=e[i].v;
		if(vis[v]) continue;
		vis[v]=1;
		dfs(u,v,sum+e[i].val,cost+f[v]);
		vis[v]=0;
	}
}
int main(){
	std::ios::sync_with_stdio(false);
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>l>>p;
	for(int i=1;i<=l;i++)
		cin>>f[i];
	for(int i=1;i<=p;i++){
		int u,v,val;
		cin>>u>>v>>val;
		add(u,v,val);
		rd[v]++;
	}
	for(int i=1;i<=l;i++){
		if(rd[i]) dfs(i,i,0,0);
	}
	printf("%.2lf\n",ans);
	return 0;
}
