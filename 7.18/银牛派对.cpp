#include<iostream>
#include<cstring>
#define inf 214748364
#define mmm 100000
using namespace std;
int n,m,cnt,hl[mmm],i,j,dis[mmm],vis[mmm],k,vv[mmm],uu[mmm],ww[mmm],maxn=0,ans[mmm];
struct node{
	int v,w,n;
}x[mmm];
void add(int u,int v,int w)
{
	x[++cnt].v=v;
	x[cnt].w=w;
	x[cnt].n=hl[u];
	hl[u]=cnt;
}
void inti()
{
	memset(x,0,sizeof(x));
    memset(dis,0,sizeof(dis));
    memset(vis,0,sizeof(vis));
    cnt=0;
    for( i=1;i<=n;i++)
    hl[i]=-1;
}
void dij(int s)
{
	for( i=1;i<=n;i++) dis[i]=inf;
	dis[s]=0;
	for(int i=1;i<=n;i++)
	{
		k=0;
		for( j=1;j<=n;j++)
		if(!vis[j]&&(!k||dis[k]>dis[j]))
		k=j;
		vis[k]=1;
		for( j=hl[k];j!=-1;j=x[j].n)
			if(!vis[x[j].v]&&(dis[k]+x[j].w<dis[x[j].v]))
				dis[x[j].v]=dis[k]+x[j].w;
	}
}
int main()
{
	int xx;
	cin>>n>>m>>xx;
	inti();
	for(int i=1;i<=m;i++)
	{
		int xc,y,z;
		cin>>xc>>y>>z;
		vv[i]=xc,uu[i]=y,ww[i]=z;
		add(xc,y,z);
	}
	dij(xx);
	for(int i=1;i<=n;i++)
	ans[i]=dis[i];
	inti(); 
	for(int i=1;i<=m;i++)
	add(uu[i],vv[i],ww[i]);
	dij(xx);
	for(int i=1;i<=n;i++)
	{
		ans[i]+=dis[i];
		maxn=max(maxn,ans[i]);
	}
	cout<<maxn;
	return 0;
}
