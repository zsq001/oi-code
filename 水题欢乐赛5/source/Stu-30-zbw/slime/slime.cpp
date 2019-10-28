#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<queue>
using namespace std;
queue<int> q;
int cnt,maxdeep,rd[10010],cd[10010],head[10010],deep[10010],fa[10010];
struct Edge{
	int v,next;
}e[10010];
void add(int u,int v){
	e[++cnt].v=v;
	e[cnt].next=head[u];
	head[u]=cnt;
}
void dfs(int x,int fx){
	deep[x]=deep[fx]+1;
	fa[x]=fx;
	for(int i=head[x];i;i=e[i].next){
		int v=e[i].v;
		if(v==fx) continue;
		dfs(v,x);
	}
}
int getfa(int x,int y){
	while(fa[x]!=fa[y]){
		x=fa[x],y=fa[y];
	}
	return fa[x];
}
int main(){
	freopen("slime.in","r",stdin);
	freopen("slime.out","w",stdout);
	int n,m,op;
	scanf("%d%d%d",&n,&m,&op);
	for(int i=1;i<=m;i++){
		int u,v;
		scanf("%d%d",&u,&v);
	}
	int ans=0;
	for(int i=1;i<=n;i++){
		if((!cd[i])||((!rd[i])&&cd[i]<=1)){
			ans++;
		}
	}
	printf("%d",ans);
}
