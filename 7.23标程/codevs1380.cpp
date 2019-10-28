#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
#define maxn 1000010
struct Edge{
	int v,next;
}E[maxn];
int ecnt=0,head[maxn];
void addedge(int u,int v){
	E[++ecnt].v=v;
	E[ecnt].next=head[u];
	head[u]=ecnt;
}
int dp[maxn][2],val[maxn];
void dfs(int x){
	for(int i=head[x];i;i=E[i].next){
		int v=E[i].v;
		dfs(v);
		dp[x][1]+=dp[v][0];
		dp[x][0]+=max(dp[v][1],dp[v][0]);
	}
	dp[x][1]+=val[x];
}
int in[maxn];
int main(){
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;++i){
		scanf("%d",&val[i]);
	}
	for(int i=1;i<=n;++i){
		int u,v;
		scanf("%d%d",&v,&u);
		addedge(u,v);
		++in[v];
	}
	for(int i=1;i<=n;++i){
		if(in[i]==0){
			dfs(i);
			printf("%d",max(dp[i][1],dp[i][0]));
			return 0;
		}
	}
	return 0;
}
