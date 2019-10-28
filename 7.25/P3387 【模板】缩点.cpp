#include<iostream>
#include<stack>
#include<queue>
#define mmm 200010
int low[mmm],dfn[mmm],m,rt,cnt=0,son=0,head[mmm],now,n,jh[mmm],vis[mmm],HEAD[mmm],ans,val[mmm],rd[mmm],dp[mmm],VAL[mmm],tot=0;
using namespace std;
struct node{
	int v,next;
}e[mmm],E[mmm];
stack<int> s;
queue<int>q;
void add(int u,int v)
{
	e[++cnt].v=v;
	e[cnt].next=head[u];
	head[u]=cnt;
}
void addd(int x,int y)
{
	E[++cnt].v=y;
	E[cnt].next=HEAD[x];
	HEAD[x]=cnt;
}
void tarjan(int x)
{
	dfn[x]=low[x]=++cnt;
	vis[x]=1;
	s.push(x);
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
			now=s.top();
			s.pop();
			jh[now]=tot;	
			VAL[tot]+=val[now];
			vis[now]=0;
		}
	}
}
void rebuild()
{
	for(int x=1;x<=n;x++)
	for(int i=head[x];i;i=e[i].next)
	{
		int v=e[i].v;
		if(jh[x]!=jh[v])
		{
			addd(jh[x],jh[v]);
			rd[jh[v]]++;
		}
	}
}
int main()
{
	int u,v;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	cin>>val[i];
	while(m--)
	{
		cin>>u>>v;
		add(u,v);
	}
	cnt=0;
	for(int i=1;i<=n;i++)
	{
		if(!dfn[i])
		tarjan(i);
	}
	cnt=0;
	rebuild();
	for(int i=1;i<=tot;i++)
	{
		if(!rd[i])
		{
			q.push(i);
			dp[i]=VAL[i];
		}
	}
	while(!q.empty())
	{
		int x=q.front();
		q.pop();
		for(int i=HEAD[x];i;i=E[i].next)
		{
			int v=E[i].v;
			dp[v]=max(dp[v],dp[x]+VAL[v]);
			rd[v]--;
			if(!rd[v])
			q.push(v);
		}
	}
	//dp[v]=max(dp[v],dp[x]+VAL[v]);
	for(int i=1;i<=tot;i++)
	{
		ans=max(ans,dp[i]);
	}
	cout<<ans<<endl;
	return 0;
}
