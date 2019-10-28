#include<bits/stdc++.h>
#define maxn 300010
using namespace std;
typedef unsigned long long ll;
const ll base=19260817;
ll w[maxn];
int n,m,op,ans,cnt,s,tot,tag[maxn],son[maxn],head[maxn],deep[maxn],low[maxn],dfn[maxn]; 
struct Edge{
	int v,next;
}e[4000010];
void add(int u,int v){
	e[++cnt].v=v;
	e[cnt].next=head[u];
	head[u]=cnt;
}
void tarjan(int x,int fa,int fl){
	low[x]=dfn[x]=++cnt;
	for(int i=head[x];i;i=e[i].next){
		int v=e[i].v;
		if(!dfn[v]){
			tarjan(v,x,fl+1);
			low[x]=min(low[x],low[v]);
			if(low[v]>=dfn[x]){
				if(x==1) s++;
				else if(!tag[x]) tag[x]=1;
			}
		}
		else if(v!=fa) low[x]=min(low[x],dfn[v]);
	}
}
ll dfs(int x,int fa){
	ll pre=0,now=0;
	deep[x]=deep[fa]+1;
	for(int i=head[x];i;i=e[i].next){
		int v=e[i].v;
		if(v==fa) continue;
		ll now=dfs(v,x);
		if(!pre) pre=now;
		else if(pre==now) tag[v]=1;
		son[x]+=son[v];
	}
	if(!now) son[x]++;
	return pre+now+son[x]*w[deep[x]];
}
void dfs2(int x,int fa){
	tag[x]|=tag[fa];
	for(int i=head[x];i;i=e[i].next){
		int v=e[i].v;
		if(v==fa) continue;
		dfs2(v,x);
	}
	if(son[x]>1) tag[x]=1;
}
int main()
{
	freopen("slime10.in","r",stdin);
	//freopen("slime.out","w",stdout);
	int u,v;
	cin>>n>>m>>op;
	ans=n;
	w[1]=1ull;
	for(int i=2;i<=300000;++i) w[i]=w[i-1]*base;
	for(int i=1;i<=m;++i){
		scanf("%d%d",&u,&v);
		add(u,v);
		add(v,u);
	}
	if(op==1){
		cnt=0;
		tarjan(1,0,1);
		if(s>=2) tag[1]=1;
	}
	else{
		dfs(1,0);
		dfs2(1,0);
	}
	for(int i=1;i<=n;++i) ans-=tag[i];
	cout<<ans<<endl;
	return 0;
}
