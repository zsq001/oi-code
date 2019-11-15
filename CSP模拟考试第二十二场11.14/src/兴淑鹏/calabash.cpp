#include<stdio.h>
#include<queue>
using namespace std;
queue <int> q;
struct X
{
	int u,v,f,n;
	double q,w;
}x[4005];
int m,n;
double d[205],e=1e-4;
bool vis[205];
bool spfa(double a)
{
	for(int i=1;i<=m;i++)
		x[i].q=x[i].w-a;
	q.push(0);
	for(int i=1;i<=n;i++)
		d[i]=100000000;
	while(!q.empty())
	{
		int t=q.front();q.pop();
		vis[t]=0;
		for(int i=x[t].f;i;i=x[i].n)
			if(d[t]+x[i].q<d[x[i].v])
			{
				d[x[i].v]=d[t]+x[i].q;
				if(!vis[x[i].v]) vis[x[i].v]=1,q.push(x[i].v);
			}
	}
	return d[n]>=-e;
}
int main()
{
	freopen("calabash.in","r",stdin);
	freopen("calabash.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++)
	{
		scanf("%d%d%lf",&x[i].u,&x[i].v,&x[i].w);
		x[i].n=x[x[i].u].f;
		x[x[i].u].f=i;
	}
	x[++m].u=0;x[m].v=1;x[m].w=0;
	x[0].f=m;
	double l=0,r=1000;
	while(r-l>=e)
	{
		double mid=(l+r)/2.0;
		if(spfa(mid)) l=mid;
		else r=mid;
	}
	printf("%.3lf",l);
	return 0;
}
