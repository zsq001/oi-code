#include<cstdio>
#include<algorithm>
#define maxn 500
using namespace std;
int ans,a[500][500],n,m,f[maxn],deep[maxn],cnt,root,q[500][500],maxx,kans,fg,l,p[maxn],tot,head[500];
struct edge{
	int v,next;
}e[maxn<<1];
void add(int u,int v)
{
	e[++cnt].v=v;
	e[cnt].next=head[u];
	head[u]=cnt;
}
int lca(int x,int y)
{
	if(deep[x]<deep[y])swap(x,y);
	int w=x;
	int z=y;
	int g;
	int d=deep[x]-deep[y];
	for(int j=20;j>=0;j--)if(d&(1<<j))x=a[x][j];
	if(x==y)
	{
		return q[w][0];
	}
	for(int j=20;j>=0;j--)
	{
		if(a[x][j]!=a[y][j])
		{
			x=a[x][j];
			y=a[y][j];
			g=j;
		}
	} 
	return q[w][a[x][g]]+q[y][a[x][g]];
}
void dfs(int x,int fa)
{
	a[x][0]=fa;
	deep[x]=deep[fa]+1;
	for(int i=head[x];i;i=e[i].next)
	{
		int v=e[i].v;
		if(v==fa)continue;
		dfs(v,x);
	}
}
void init()
{
	for(int j=1;(1<<j)<=n;j++)
	{
		for(int i=1;i<=n;i++)
		{
			if(deep[i]>=(1<<j))
			{
				a[i][j]=a[a[i][j-1]][j-1];
				q[i][j]=q[a[i][j-1]][j-1];
			}
		}
	}
}
int main()
{
	int u,v,k;
	freopen("tree.in","r",stdin);
	freopen("tree.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<n;i++)
	{
		scanf("%d%d%d",&u,&v,&k);
		add(u,v);
		q[v][0]=k;
		f[v]=1;
		kans+=k;
	}
	if(n==m)
	{
		printf("%d",kans);
		return 0;
	}
	for(int i=1;i<=n;i++)
	{
		if(f[i]==0)
		{
			root=i;
			break;
		}
	}
	dfs(root,0);
	init();
	for(int i=1;i<=n;i++)
	{
		if(i<=m)
		{
			p[++tot]=lca(i,i+1);
			if(p[tot]>maxx)
			{
				maxx=p[tot];
				fg=tot;
			}
			ans+=p[tot];
		}
		else
		{
			l=lca(i,i+1);
			if(l<maxx)
			{
				p[fg]=l;
				ans-=maxx;
				ans+=p[fg];
				for(int j=1;j<=m;j++)
				{
					if(p[j]>maxx)
					{
						maxx=p[j];
					}
				}
			}

		}
	}
	printf("%d",ans);
	return 0;
}
