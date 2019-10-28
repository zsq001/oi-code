#include<iostream>
#include<stack>
#define mmm 100000
using namespace std;
struct node {
	int v,next;
}e[50010];
stack<int> s;
int dfn[mmm],low[mmm],cnt,tot=0,ans=0,now,n,m,vis[mmm],head[mmm],jh[mmm],num[mmm];
void add(int u,int v)
{
	e[++cnt].v=v;
	e[cnt].next=head[u];
	head[u]=cnt;
}
void tarjan(int x)
{
	vis[x]=1;
	s.push(x);
	dfn[x]=low[x]=++cnt;
	for(int i=head[x];i;i=e[i].next)
	{
		int v=e[i].v;
		if(!dfn[v])
		{
			tarjan(v);
			low[x]=min(low[x],low[v]);
		}
		else if(vis[v]) low[x]=min(low[x],low[v]);
	}
	if(dfn[x]==low[x])
	{
		tot++;
		now=-1;
		while(now!=x)
		{
			now=s.top();
			s.pop();
			vis[now]=0;
			num[tot]++;
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
	cnt=0;
	for(int i=1;i<=n;i++)
	if(!dfn[i])
	tarjan(i);
	for(int i=1;i<=tot;i++)
	if(num[i]>1)
	ans++;
	cout<<ans;
	return 0; 
}
