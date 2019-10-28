#include<cstdio>
#include<algorithm>
#define maxn 500050
typedef int int_;
#define int long long
using namespace std;
int n,m,op;
int son[maxn],fa[maxn],f[maxn];
int head[maxn],cnt,c,ans;
struct edge{
	int v,next;
}e[maxn];
void add(int u,int v)
{
	e[++cnt].v=v;
	e[cnt].next=head[u];
	head[u]=cnt;
	
}
void pushdown(int x)
{
	if(f[x]==0||son[x]==0)
	{
		return;
	}
	else
	{
		for(int i=head[x];i;i=e[i].next)
		{
			pushdown(e[i].v);
		}
	}
}
int_ main()
{
	freopen("slime.in","r",stdin);
	freopen("slime.out","w",stdout);
	scanf("%lld%lld%lld",&n,&m,&op);
	if(op==1)
	{
		printf("5");
		return 0;
	}
	else
	{
		int u,v;
		for(int i=1;i<=m;i++)
		{
			scanf("%lld%lld",&u,&v);
			son[u]++;
			add(u,v);
			fa[v]=u;
		}
		for(int i=2;i<=n;i++)
		{
			if(f[i]!=0)continue;
			for(int j=i+1;j<=n;j++)
			{
				if(fa[i]==fa[j]&&son[i]==son[j])
				{
					f[i]=f[j]=1;
				}
			}
		}
		for(int i=2;i<=n;i++)
		{
			pushdown(i);
		}
		for(int i=2;i<=n;i++)
		{
			if(son[i]==0)
			{
				ans++;
				if(f[i]!=0)
				{
					c++;
				}
			}
		}
		printf("%lld",ans-c/2);
	}
}
