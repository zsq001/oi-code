#include<cstdio>
#include<cstring>
using namespace std;
int head[300001],n,m,op,ecnt,ans;
bool vis[300001];
struct node{
	int v,next;
}e[300001];
void add(int u,int v){
	e[++ecnt].v=v;
	e[ecnt].next=head[u];
	head[u]=ecnt;
}
void dfs(int x,int fa,int cut){
	vis[x]=1;
	for(int i=head[x];i;i=e[i].next){
		int v=e[i].v;
		if(v==fa||vis[v]||v==cut)continue;
		dfs(v,x,cut);
	}
}
bool judge(int x){
	memset(vis,0,sizeof(vis));
	dfs(e[head[x]].v,x,x);
	for(int i=1;i<=n;i++){
		if(vis[i]==0&&i!=x)return 0;
	}
	return 1;
}
int main(){
	int u,v;
	freopen("slime.in","r",stdin);
	freopen("slime.out","w",stdout);
	scanf("%d%d%d",&n,&m,&op);
	if(op==1){
		for(int i=1;i<=m;i++){
			scanf("%d%d",&u,&v);
			add(u,v);
			add(v,u);
		}
		for(int i=1;i<=n;i++){
			if(judge(i)){
				ans++;
				//printf("%d\n",i);
			}
		}
		printf("%d",ans);
	}
}
