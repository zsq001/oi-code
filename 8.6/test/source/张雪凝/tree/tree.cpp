#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int dp[101][101],head[101],cnt,m;
struct no{
	int v,w,next;
}e[1001];
void add(int u,int v,int w){
	e[++cnt].v=v;
	e[cnt].next=head[u];
	e[cnt].w=w;
	head[u]=cnt;
}
void dfs(int x,int fa){
	for(int i=head[x];i;i=e[i].next){
		int v=e[i].v;
		dp[x][1]=0;
		if(v==fa)continue;
		dfs(v,x);
		for(int j=2;j<=m;j++){
			dp[x][j]=min(dp[x][j],dp[v][j-1]+e[i].w);
		}
	}
}
int main(){
	int n,u,v,w;
	freopen("tree.in","r",stdin);
	freopen("tree.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<n;i++){
		scanf("%d%d%d",&u,&v,&w);
		add(u,v,w);
		add(v,u,w);
	}
	dfs(1,0);
	int ans=200000000;
	for(int i=1;i<=n;i++){
		ans=min(dp[i][m],ans);
	}
	printf("%d",ans);
}
