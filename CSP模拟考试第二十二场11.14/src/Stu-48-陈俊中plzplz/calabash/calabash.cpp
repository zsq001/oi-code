#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
#define maxn 2010
using namespace std;

int n,m,cnt,head[210],vis[210],vcnt;
const int qaq=1e9+7;
priority_queue<pair<double,int> > q;
struct edge
{
	int v,w,next;
}E[maxn];
double dis[210];

void add(int u,int v,int w)
{
	E[++cnt].v=v;
	E[cnt].w=w;
	E[cnt].next=head[u];
	head[u]=cnt;
}

void di(double mid)
{
	for(int i=1;i<=n;i++) dis[i]=qaq;
	dis[1]=-mid;
//	vcnt=1;
	q.push(make_pair(mid,1));
	while(!q.empty())
	{
		int x=q.top().second;
		q.pop();
		if(vis[x]) continue;
		vis[x]=1;
		for(int i=head[x];i;i=E[i].next)
		{
			int v=E[i].v,w=E[i].w;
			if(vis[v]) continue;
			if(dis[v]>=dis[x]+w-mid)
			{
				dis[v]=dis[x]+w-mid;
				q.push(make_pair(-dis[v],v));
			}
//			if(dis[v]>((double)(dis[x]*vcnt)+w)/(vcnt+1))
//			{
//				dis[v]=(double)((dis[x]*vcnt)+w)/(vcnt+1);
//				vcnt++;
//				q.push(make_pair(-dis[v],v));
//			}
		}
	}
}

int main()
{
	freopen("calabash.in","r",stdin);
	freopen("calabash.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++)
	{
		int u,v,w;
		scanf("%d%d%d",&u,&v,&w);
		add(u,v,w);
	}
	double l=0,r=1e3;
	while(l+1e-5<r)
	{
		double mid=(l+r)/2.0;
		memset(vis,0,sizeof(vis));
		di(mid);
		if(dis[n]>1e-5) l=mid;
		else r=mid;
	}
//	di();
	printf("%.3lf",l);
	return 0;
}
