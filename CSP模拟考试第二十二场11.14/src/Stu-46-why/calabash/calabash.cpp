 #include<cstdio>
#include<algorithm>
#include<queue>
#define maxn 2010
using namespace std;
int n,m;
double minn=100000000.00;
struct edge{
	int to,next,dis;
}e[maxn];
int head[maxn],hl[maxn];
int cnt,vis[maxn];
int dis[maxn];
void add(int u,int v,int d)
{
	e[++cnt].to=v;
	e[cnt].dis=d;
	e[cnt].next=head[u];
	head[u]=cnt;
}
void dfs(int now,double num,double ans)
{
	if(vis[now]==1)return;
	vis[now]=1;
	if(now==1)
	{
		if(ans/num<=minn)
		minn=ans/num;
		return;
	}
	for(int i=head[now];i;i=e[i].next)
	{
		int y=e[i].to;
		dfs(e[i].to,num+1,ans+e[i].dis);
		vis[y]=0;
	}
}
int main()
{
	freopen("calabash.in","r",stdin);
	freopen("calabash.out","w",stdout);
	scanf("%d%d",&n,&m);
	int u,v,d;
	for(int i=1;i<=n;i++)dis[i]=0x7fffffff;
	for(int i=1;i<=m;i++)
	{
		scanf("%d%d%d",&u,&v,&d);
		add(v,u,d);
	}
	if(n==2&&m==1)
	{
		int ans=d/2;
		printf("%.3lf",ans);
		return 0; 
	}
	dfs(n,1,0);
	printf("%.3lf",minn);
}
