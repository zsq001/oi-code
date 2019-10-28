#include<iostream> 
#define mmm 500010
using namespace std;
int f[mmm][21],head[mmm],m,rt,s,deep[mmm],cnt=0,n;
struct node{
	int v,next;
}e[mmm>>1];
void add(int u,int v)
{
	e[++cnt].v=v;
	e[cnt].next=head[u];
	head[u]=cnt;
}
void init()
{
	for(int j=1;(1<<j)<=n;j++)
	for(int i=1;i<=n;i++)
	if(deep[i]>=(1<<j))
	f[i][j]=f[f[i][j-1]][j-1];
}
void dfs(int x,int fa)
{
	f[x][0]=fa;
	deep[x]=deep[fa]+1;
	for(int i=head[x];i;i=e[i].next)
	{
		int v=e[i].v;
		if(v==fa)
		continue;
		dfs(v,x);
	}
} 
int lca(int x,int y)
{
	if(deep[x]<deep[y])
	swap(x,y);
	int d=deep[x]-deep[y];
	for(int j=20;j>=0;j--)
	{
		if(d&(1<<j))
		x=f[x][j];
		if(x==y)
		return x;
		for(int j=20;j>=0;j--)
		{
			if(f[x][j]!=f[y][j])
			{
				x=f[x][j];
				y=f[y][j];
			}
		}
	}
	return f[x][0];
}
int main()
{
	int u,v;
	cin>>n>>m>>rt;
	for(int i=1;i<=n;i++)
	{
		cin>>u>>v;
		add(u,v);
		add(v,u);
	}
	dfs(s,0);
	init();
	for(int i=1;i<=m;i++)
	{
		cin>>u>>v;
		cout<<lca(u,v);
	}
	return 0;
}
