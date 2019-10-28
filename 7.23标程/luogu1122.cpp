#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
#define maxn 1000010
struct Edge{
	int v,next;
}E[maxn];
int dp[maxn];
int ecnt=0,head[maxn],a[maxn];
void addedge(int u,int v){
	E[++ecnt].v=v;
	E[ecnt].next=head[u];
	head[u]=ecnt;
}
void dfs(int x,int fx){
	dp[x]=a[x];
	for(int i=head[x];i;i=E[i].next){
		int v=E[i].v;
		if(v==fx) continue;
		dfs(v,x);
		dp[x]+=dp[v];
	}
	if(dp[x]<0) dp[x]=0;
}
int main(){
	int n,bns=-2147483647;
	scanf("%d",&n);
	for(int i=1;i<=n;++i){
		scanf("%d",&a[i]);
		bns=max(a[i],bns);
	}
	if(bns<0){
		printf("%d",bns);
		return 0;
	}
	for(int i=1;i<n;++i){
		int u,v;
		scanf("%d%d",&u,&v);
		addedge(u,v);
		addedge(v,u);
	}
	dfs(1,0);
	int ans=0;
	for(int i=1;i<=n;++i){
		ans=max(ans,dp[i]);
	}
	printf("%d",ans);
	return 0;
}
