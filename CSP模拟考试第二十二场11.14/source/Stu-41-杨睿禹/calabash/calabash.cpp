#include<cstdio>
#include<iostream>
#include<algorithm>
#include<stack>
#include<queue>
#include<cmath>
#include<cstring>
#define N 500100
#define M 5010
#define P 510
#define oo 1000000007
using namespace std;
struct edge{
	int u,v,val,next;
}e[N];
int cnt,head[N],pt[N],cst[N],vis[N],n,m;
void add(int u,int v,int val){
	e[++cnt].u=u;
	e[cnt].v=v;
	e[cnt].val=val;
	e[cnt].next=head[u];
	head[u]=cnt;
}
double ans=oo,tmpans;
void dfs(int x,int fa){
	if(x==n){
		ans=min(ans,tmpans);
		return ;
	}
	for(int i=head[x];i;i=e[i].next){
		int v=e[i].v;
		if(v==fa) continue;
		if(vis[v]) continue;
		vis[v]=1;
		pt[v]=pt[x]+1;
		cst[v]=cst[x]+e[i].val;
		tmpans=(double)(cst[v]/pt[v]);
		dfs(v,x);
		vis[v]=0;
	}
}
int main(){
	std::ios::sync_with_stdio(false);
	freopen("calabash.in","r",stdin);
	freopen("calabash.out","w",stdout);
	cin>>n>>m;
	while(m--){
		int u,v,val;
		cin>>u>>v>>val;
		add(u,v,val);
	}
	pt[1]=1;
	dfs(1,0);
	printf("%.3lf\n",ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
