#include <cstdio>
#include <algorithm>
#define maxn 3010
using namespace std;
struct edge{
	int u,v,w,next;
}e[maxn];
int ans[maxn],cnt,head[maxn],vis[maxn],w[maxn];

void add(int u,int v,int w) {
	e[++cnt].u = u;
	e[cnt].v = v;
	e[cnt].w = w;
	e[cnt].next = head[u];
	head[u] = cnt;
}
void dfs(int q,int k,int ret){
	if(k==1) ans[q]=min(ans[q],ret);
	for(int i=head[q];i;i=e[i].next){
		int v=e[i].v;
		if(vis[v]==1) continue;
		k--;
		ret+=e[i].w;
		vis[v]=1;
		dfs(v,k,ret);
		
	}
}
int main() {
	int n,k;
	freopen("tree.in","r",stdin);
	freopen("tree.out","w",stdout);
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++) ans[i]=1<<29;
	for (int i = 1; i < n; i++) {
		int u,v;
		scanf("%d%d%d",&u,&v,&w[i]);
		add(u,v,w[i]);
		add(v,u,w[i]);
	}
	if(k == n-1){
		sort(w+1,w+n);
		int sum=0;
		for(int i=1;i<=k;i++){
			sum+=w[i];
		}
		printf("%d",sum);
		return 0;
	}
	for(int i=1;i<=n;i++){
		dfs(i,k,0);
	}
	int in=1<<29;
	for(int i=1;i<=n;i++) in=min(in,ans[i]);
	printf("%d",in);
	return 0;
}
