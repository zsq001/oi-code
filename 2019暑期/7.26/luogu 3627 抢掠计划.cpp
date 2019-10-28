#include<bits/stdc++.h>
#define maxn 500010
#define inf 1<<29
using namespace std;
typedef long long ll;
int n,m,cnt,tot,ans,now,s,w[maxn],W[maxn],dis[maxn],head[maxn],HEAD[maxn],jh[maxn],low[maxn],dfn[maxn],vis[maxn];
queue<int>Q;
stack<int>S;
struct Edge{
	int v,next;
}e[maxn<<1],E[maxn<<1];
void add(int u,int v){
	e[++cnt].v=v;
	e[cnt].next=head[u];
	head[u]=cnt; 
}
void ADD(int u,int v){
	E[++cnt].v=v;
	E[cnt].next=HEAD[u];
	HEAD[u]=cnt;
}
void tarjan(int x){
	dfn[x]=low[x]=++cnt;
	S.push(x);
	vis[x]=1;
	for(int i=head[x];i;i=e[i].next){
		int v=e[i].v;
		if(!dfn[v]){
			tarjan(v);
			low[x]=min(low[x],low[v]);
		}
		else if(vis[v]) low[x]=min(low[x],dfn[v]); 
	}
	if(dfn[x]==low[x]){
		tot++;
		now=-1;
		while(now!=x){
			now=S.top();
			S.pop();
			jh[now]=tot;
			vis[now]=0; 
		}
	}
}
void rebuild(){
	for(int x=1;x<=n;++x){
		for(int i=head[x];i;i=e[i].next){
			int v=e[i].v;
			if(jh[x]!=jh[v]) ADD(jh[x],jh[v]);
		}
		W[jh[x]]+=w[x];
	}
}
void spfa(){
	dis[jh[s]]=W[jh[s]];
	Q.push(jh[s]);
	while(!Q.empty()){
		int x=Q.front();
		Q.pop();
		vis[x]=0;
		for(int i=HEAD[x];i;i=E[i].next){
			int v=E[i].v;
			if(dis[x]+W[v]>dis[v]){
				dis[v]=dis[x]+W[v];
				if(!vis[v]){
					vis[v]=1;
					Q.push(v);
				}
			}
		}
	}
}
int main()
{
	int u,v;
	cin>>n>>m;
	while(m--){
		cin>>u>>v;
		add(u,v);
	}
	for(int i=1;i<=n;++i) cin>>w[i];
	cin>>s>>m;
	cnt=0;
	for(int i=1;i<=n;++i) if(!dfn[i]) tarjan(i);
	cnt=0;
	rebuild();
	spfa();
	for(int i=1;i<=m;++i){
		cin>>v;
		ans=max(ans,dis[jh[v]]);
	}
	cout<<ans<<endl;
	return 0;
}
