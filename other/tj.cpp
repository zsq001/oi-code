#include<iostream>
#include<cstdio>
#include<stack>
using namespace std;
struct node{
	int v,next;
}e[1001100];
stack <int> s;
int n,m,cnt=0;
void add(int u,int v)
{
	a[++cnt].v=v;
	a[cnt].next=head[u];
	head[u]=cnt;
}
void tarjan(int x)
{
	dfn[x]=low[n]=++tot;
	s.push(x);
	in[x]=1;
	for(int i=head[x];i;i=e[i].next)
	{
		int xx=e[i].v;
		if(dfn(xx))
		{
			tarjan(xx);
			low[x]=min(low[xx],low[x]);
		}
		else if (in[xx])
			 low[x]=min(low[xx],low[x]);
		
	}
}
int main()
{
	cin>>n>>m;
	for(int i=1;i<=m;i++)
	{
		int x,y;
		cin>>x>>y;
		add(x,y);
	}
	for(int i=1;i<=n;i++)
		if(!dfn[i])
			tarjan(i);
}
