#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
#define maxn 1010
int dp[maxn][maxn];
int val[maxn];
struct Edge{
	int v,next;
}E[maxn];
int ecnt=0,head[maxn];
void addedge(int u,int v){
	E[++ecnt].v=v;
	E[ecnt].next=head[u];
	head[u]=ecnt;
}
int m;
void dfs(int x){
	dp[x][1]=val[x];
	for(int i=head[x];i;i=E[i].next){
		int v=E[i].v;
		dfs(v);
		for(int k=m;k;--k){
			for(int j=k-1;j;--j){
				dp[x][k]=max(dp[x][k],dp[x][k-j]+dp[v][j]);
			}
		}
	}
}
int in[maxn];
int main(){
	int n;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;++i){
		int u;
		scanf("%d%d",&u,&val[i]);
		addedge(u,i);
	}
	m++;
	dfs(0);
	printf("%d",dp[0][m]);
	return 0;
}
