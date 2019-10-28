#include<cstdio>
#include<algorithm>
#include<cstring>
#include<queue>
#define maxn 100010
using namespace std;
const int inf=1e9+7;
queue<int> q;
int w[101];
long long cnt,ans,n,k,root,dp[1010][1010],vis[maxn],head[maxn],dis[1010][1010];
struct Edge{
	int v,w,next;
}e[maxn<<1];
void add(int u,int v,int w){
	e[++cnt].v=v;
	e[cnt].w=w;
	e[cnt].next=head[u];
	head[u]=cnt;
}
void spfa(int s){
	dis[s][s]=0;
	vis[s]=1;
	q.push(s);
	while(!q.empty()){
		int x=q.front();
		q.pop();
		vis[x]=0;
		for(int i=head[x];i;i=e[i].next){
			int v=e[i].v,w=e[i].w;
			if(dis[s][v]>dis[s][x]+w){
				dis[s][v]=dis[s][x]+w;
				if(!vis[v]){
					q.push(v);
					vis[v]=1;
				}
			}
		}
	}
}
void dfs(int x){
	if(cnt>=k) return;
	for(int i=head[x];i;i=e[i].next){
		int v=e[i].v;
		if(dp[cnt][v])
		dp[cnt][v]=max(dp[cnt-1][x]+dis[x][v],dp[cnt][v]);
		else dp[cnt][v]=dp[cnt-1][x]+dis[x][v];
		dfs(v);
	}
	cnt++;
}
int main(){
	freopen("tree.in","r",stdin);
	freopen("tree.out","w",stdout);
	scanf("%d%d",&n,&k);
	for(int i=1;i<n;i++){
		int u,v,W;
		scanf("%d%d%d",&u,&v,&W);
		add(u,v,W);
		w[i]=W;
	}
	if(n<=10){
		sort(w+1,w+n+1);
		for(int i=1;i<=k;i++){
			ans+=w[i];
		}
		printf("%d",ans);
		return 0;
	}
	ans=inf;
	memset(dis,0x7f,sizeof dis);
	for(int i=1;i<=n;i++){
		spfa(i);
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			printf("dis[%d][%d]=%d\n",i,j,dis[i][j]);
		}
	}
	for(int i=1;i<=n;i++){
		dp[1][i]=0,cnt=0;
		dfs(i);
		for(int j=1;j<=n;j++){
			if(j==i) continue;
			if(dp[k][j]>0)
			ans=min(ans,dp[k][j]);
		}
	}
	printf("%d",ans);
	//for(int i=1;i<=n;i++) printf("dis[%d]=%d\n",i,dis[i]);
}
