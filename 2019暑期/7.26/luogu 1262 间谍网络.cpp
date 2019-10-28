#include<bits/stdc++.h>
#define l 3010
#define inf 1e9
using namespace std;
stack<int>S;
struct X{
	int v,next;
}e[8010];
int n,p,r,cnt,num,ans,X[l],Y[l],m[l],M[l],vis1[l],vis2[l],hl[l],rd[l],dfn[l],low[l],jh[l];
void dfs(int x)
{
	vis1[x]=1;
	for(int i=hl[x];i;i=e[i].next) if(!vis1[e[i].v]) dfs(e[i].v); 
}
void tarjan(int x)
{
	vis1[x]=vis2[x]=1;
	dfn[x]=low[x]=++cnt;
	S.push(x);
	for(int i=hl[x];i;i=e[i].next){
		int to=e[i].v;
		if(!vis1[to]){
			tarjan(to);
			low[x]=min(low[x],low[to]);
		}
		else if(vis2[to]) low[x]=min(low[x],dfn[to]);
	}
	if(low[x]==dfn[x])
	{
		int now=-1;
		++num;
		while(now!=x){
			now=S.top();
			S.pop();
			jh[now]=num;
			vis2[now]=0; 
			if(m[now]) M[num]=min(M[num],m[now]);
		}
		if(M[num]==inf) M[num]=0;
	}
}
void rebuild()
{
	for(int i=1;i<=n;++i)
		for(int j=hl[i];j;j=e[j].next)
			if(jh[i]!=jh[e[j].v]) rd[jh[e[j].v]]=1;
}
void add(int x,int y)
{
	e[++cnt].v=y;
	e[cnt].next=hl[x];
	hl[x]=cnt;
}
int main()
{
	cin>>n>>p;
	int x,y;
	for(int i=1;i<=p;++i){
		cin>>x>>y;
		m[x]=y;
	}
	cin>>r; 
	for(int i=1;i<=r;++i){
		cin>>x>>y;
		add(x,y);
	}
	for(int i=1;i<=n;++i) if(m[i]&&!vis1[i]) dfs(i);
	for(int i=1;i<=n;++i){
		if(!vis1[i]){
			cout<<"NO"<<endl;
			cout<<i<<endl;
			return 0;
		}
	}
	for(int i=1;i<=l;++i) M[i]=inf;
	memset(vis1,0,sizeof(vis1)),cnt=0;
	for(int i=1;i<=n;++i) if(!vis1[i]) tarjan(i);
	rebuild();
	for(int i=1;i<=num;++i){
		if(!rd[i]) ans+=M[i];
	}
	cout<<"YES"<<endl;
	cout<<ans<<endl; 
	return 0;
}
