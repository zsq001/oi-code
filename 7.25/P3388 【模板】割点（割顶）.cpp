#include<iostream>
#define mmm 200010
int low[mmm],dfn[mmm],rt,cnt=0,son=0,head[mmm],ans[mmm],tot=0;
using namespace std;
struct node{
	int next,v;
}e[mmm];
void add(int x,int y)//½¨±ß 
{
	e[++cnt].v=y;
	e[cnt].next=head[x];
	head[x]=cnt;
}
void tarjan(int x,int fa)
{
	low[x]=dfn[x]=++cnt;
	for(int i=head[x];i;i=e[i].next)
	{
		int v=e[i].v;
		if(!dfn[v])
		{
			tarjan(v,x);
			low[x]=min(low[x],low[v]);
			if(low[v]>=dfn[x])
			{
				if(x==rt)
				son++;
				else if(!ans[x])
				{
					ans[x]=1;
					tot++;
				}
			}
		}
		else if(v!=fa)
		low[x]=min(low[x],dfn[v]);
	}
}
int main()
{
	//freopen("1.in","r",stdin);
	int u,v,n,m;
	cin>>n>>m;
	while(m--)
	{
		cin>>u>>v;
		add(u,v);
		add(v,u);
	}
	cnt=0;
	for(int i=1;i<=n;i++)
	{
		if(!dfn[i])
		tarjan(rt=i,0);
		if(son>=2)
		{
			ans[rt]=1;
			tot++;
		}
		son=0;
	}
	cout<<tot<<endl;
	for(int i=1;i<=n;i++)
	if(ans[i])
	cout<<i<<" ";
	return 0;
}
