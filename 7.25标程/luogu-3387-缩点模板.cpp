#include<bits/stdc++.h>
#define maxn 200010
#define inf 1<<29
using namespace std;
typedef long long ll;
int n,m,cnt,tot,ans,now,val[maxn],VAL[maxn],head[maxn],HEAD[maxn],jh[maxn],low[maxn],dfn[maxn],vis[maxn],rd[maxn],f[maxn];
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
	vis[x]=1;
	S.push(x);
	for(int i=head[x];i;i=e[i].next){
		int v=e[i].v;
		if(!dfn[v]){
			tarjan(v);
			low[x]=min(low[x],low[v]);
		}
		else if(vis[v]) low[x]=min(low[x],dfn[v]);
	}
	if(low[x]==dfn[x]){
		tot++;
		now=-1;
		while(now!=x){
			now=S.top();
			S.pop();
			jh[now]=tot;
			VAL[tot]+=val[now];
			vis[now]=0;
		}
	}
}
void rebuild(){
	for(int x=1;x<=n;++x)
		for(int i=head[x];i;i=e[i].next){
			int v=e[i].v;
			if(jh[x]!=jh[v]){
				ADD(jh[x],jh[v]);
				rd[jh[v]]++;
			}
		}
}
int main()
{
	int u,v;
	cin>>n>>m;
	for(int i=1;i<=n;++i) cin>>val[i];
	while(m--){
		cin>>u>>v;
		add(u,v);
	} 
	cnt=0;
	for(int i=1;i<=n;++i) if(!dfn[i]) tarjan(i);
	cnt=0;
	rebuild();
	for(int i=1;i<=tot;++i)
		if(!rd[i]){
			Q.push(i);
			f[i]=VAL[i];
		}
	while(!Q.empty()){
		int x=Q.front();
		Q.pop();
		for(int i=HEAD[x];i;i=E[i].next){
			int v=E[i].v;
			f[v]=max(f[v],f[x]+VAL[v]);
			rd[v]--;
			if(!rd[v]) Q.push(v);
		}
	}
	for(int i=1;i<=tot;++i) ans=max(ans,f[i]);
	cout<<ans<<endl;
	return 0;
}
