#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
struct shit{
	int aim,next,fro;
}e[1010000];
bool vis[2100][2100];
int point,fa[21000],head[21000];
void fuck(int v,int u)
{
	e[++point].aim=v;
	e[point].next=head[u];
	e[point].fro=u;
	head[u]=point;
}
bool findd(int xx)
{
	for(int i=head[xx];i;i=e[i].next)
	{
		int v=e[i].aim;
		if(fa[v]==xx||vis[xx][v])continue;
		vis[xx][v]=true;
		if(findd(fa[v])||!fa[v])
		{
			fa[v]=xx;
			return true;
		}
	}
	return false;
}
int n,m,y,x,ans,a[110000],b[110000];
int main()
{
	freopen("match.in","r",stdin);
	freopen("match.out","w",stdout);
	scanf("%d%d%d%d",&n,&m,&x,&y);
	for(int i=1;i<=n;i++)scanf("%d",a+i);
	for(int i=1;i<=m;i++)scanf("%d",b+i);
	for(int i=1;i<=n;i++)
	{
		int s=lower_bound(b+1,b+m+1,a[i]-x)-b;
		int t=upper_bound(b+1,b+m+1,a[i]+y)-b;
		for(int j=s;j<t;j++)
			fuck(j,i);
	}
	for(int i=1;i<=n;i++)
	{
		memset(vis,false,sizeof(vis));
		if(findd(i))ans++;
	}
	printf("%d",ans);
	return 0;
}
