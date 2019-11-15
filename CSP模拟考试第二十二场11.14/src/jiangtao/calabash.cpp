#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
struct node
{
	int v,w,next;
}e[4000];
int head[4000],n,cnt,k=2147483647,q[40000],d[4000];
bool vis[4000];
void ins(int u,int v,int w)
{
	e[++cnt].v=v;
	e[cnt].next=head[u];
	e[cnt].w=w;
	head[u]=cnt;
}
void spfa()
{
	memset(d,127/3,sizeof(d));
	int h=0,t=0;q[0]=1;vis[1]=true;d[1]=0;
	while(h<=t)
	{
		int u=q[h++];
		for(int p=head[u];p;p=e[p].next)
		{
			int v=e[p].v;
			if(d[v]>d[u]+e[p].w)
			{
				d[v]=d[u]+e[p].w;
				if(!vis[v])
				{
					vis[v]=true;
					q[++t]=v;
				}
			}
		}
		vis[u]=false;
	}
}
void dfs(int m,int dep)
{
	if(m==n){k=min(k,dep);return;}
	for(int p=head[m];p;p=e[p].next)
	if(!vis[e[p].v])vis[e[p].v]=true,dfs(e[p].v,dep+1),vis[e[p].v]=false;
}
int main()
{
	int m,x,y,z;
	freopen("calabash.in","r",stdin);
	freopen("calabash.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++)
	{
	  scanf("%d%d%d",&x,&y,&z);ins(x,y,z);
    }
	spfa();dfs(1,1);
	printf("%.3lf\n",(double)d[n]/k);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
