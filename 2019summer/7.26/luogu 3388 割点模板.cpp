#include<bits/stdc++.h>
#define maxn 200010
#define inf 1<<29
using namespace std;
typedef long long ll;
int n,m,rt,cnt,son,tot,head[maxn],low[maxn],dfn[maxn],ans[maxn];
struct Edge{
	int v,next;
}e[maxn<<1];
void add(int u,int v){
	e[++cnt].v=v;
	e[cnt].next=head[u];
	head[u]=cnt; 
}
void tarjan(int x,int fa){
	low[x]=dfn[x]=++cnt;
	for(int i=head[x];i;i=e[i].next){
		int v=e[i].v;
		if(!dfn[v]){
			tarjan(v,x);
			low[x]=min(low[x],low[v]);
			if(low[v]>=dfn[x]){
				if(x==rt) son++;
				else if(!ans[x]){
					ans[x]=1;
					tot++;
				}
			}
		}
		else if(v!=fa) low[x]=min(low[x],dfn[v]);
	}
}
int main()
{
	int u,v;
	cin>>n>>m;
	while(m--){
		cin>>u>>v;
		add(u,v);
		add(v,u);
	}
	cnt=0;
	for(int i=1;i<=n;++i){
		if(!dfn[i]) tarjan(rt=i,0);
		if(son>=2) ans[rt]=1,tot++;
		son=0;
	}
	cout<<tot<<endl;
	for(int i=1;i<=n;++i) if(ans[i]) cout<<i<<" ";
	return 0;
}
