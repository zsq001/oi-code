#include<iostream>
#include<queue>
#include<stack>
#define mmm 500010
using namespace std;
int low[mmm],dfn[mmm],W[mmm],dis[mmm],w[mmm],s,m,rt,cnt=0,son=0,x,head[mmm],now,n,jh[mmm],vis[mmm],HEAD[mmm],ans,val[mmm],rd[mmm],dp[mmm],VAL[mmm],tot=0;
struct node{
	int v,next;
}e[mmm],E[mmm];
stack<int> S;
queue<int>q;
void add(int u,int v)
{
	e[++cnt].v=v;
	e[cnt].next=head[u];
	head[u]=cnt;
}
void ADD(int u,int v)
{
	E[++cnt].v=v;
	E[cnt].next=HEAD[u];
	HEAD[u]=cnt;
}
void tarjan(int x)
{
	dfn[x]=low[x]=++cnt;
	vis[x]=1;
	S.push(x);
	for(int i=head[x];i;i=e[i].next)
	{
		int v=e[i].v;
		if(!dfn[v])
		{
			tarjan(v);
			low[x]=min(low[x],low[v]);
		}
		else if(vis[v])
		low[x]=min(low[x],dfn[v]);
	}
	if(low[x]==dfn[x])
	{
		tot++;
		now=-1;
		while(now!=x)
		{
			now=S.top();
			S.pop();
			jh[now]=tot;
			VAL[tot]+=val[now];
			vis[now]=0;
		}
	}
}
void rebuild()
{
	for(int j=1;j<=n;j++)
	{
		for(int i=head[j];i;i=e[i].next)
		{
			int v=e[i].v;
			if(jh[j]!=jh[v])
			ADD(jh[j],jh[v]);
		}
		W[jh[j]]+=w[j];
	}
} 
void spfa()
{
	dis[jh[s]]=W[jh[s]];
	q.push(jh[s]);
	while(!q.empty())
	{
		int x=q.front();
		q.pop();
		vis[x]=0;
		for(int i=HEAD[x];i;i=E[i].next)
		{
			int v=E[i].v;
			if(dis[x]+W[v]>dis[v])
			{
				dis[v]=dis[x]+W[v];
				if(!vis[v])
				{
					vis[v]=1;
					q.push(v);
				}
			}
		}
	}
}
int main()
{
	int u,v;
	cin>>n>>m;
	while(m--)
	{
		cin>>u>>v;
		add(u,v);
	}
	for(int i=1;i<=n;i++)
	cin>>w[i];
	cin>>s>>m;
	cnt=0;
	for(int i=1;i<=n;i++)
	{
		if(!dfn[i])
		tarjan(i);
	}
	cnt=0;
	rebuild();
	spfa();
	for(int i=1;i<=m;i++)
	{
		cin>>v;
		ans=max(ans,dis[jh[v]]);
	}
	cout<<ans;
	return 0;
}
