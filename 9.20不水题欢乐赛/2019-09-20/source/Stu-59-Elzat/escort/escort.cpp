#include<cstdio>
#include<algorithm>
#include<queue>
using namespace std;
const int inf = 0x3f3f3f3f;
int n,m,tt,ss,X,s,t;
struct edge{
	int u,v,w,next;
}e[20010];
int head[10010],cnt;
int dis[10010],vis[10010];
priority_queue< pair<int,int> >Q;

void add(int u,int v,int w)
{
	e[++cnt].u = u;
	e[cnt].v = v;
	e[cnt].w = w;
	e[cnt].next = head[u];
	head[u] = cnt;
}

void dijkstra(int x)
{
	for(int i = 1;i <= n;i ++) dis[i] = inf,vis[i] = 0;
	dis[x] = 0;
	Q.push(make_pair(0,x));
	while(!Q.empty())
	{
		x = Q.top().second;
		Q.pop();
		if(vis[x]) continue;
		vis[x] = 1;
		for(int i = head[x];i;i = e[i].next)
		{
			int v = e[i].v;
			if(!vis[v] && dis[v] > dis[x] + e[i].w)
			{
				dis[v] = dis[x] + e[i].w;
				Q.push(make_pair(-dis[v],v));
			}
		}
	}
}

int main()
{
	freopen("escort.in","r",stdin);
	freopen("escort.out","w",stdout);
	scanf("%d%d%d%d%d",&n,&m,&tt,&ss,&X);
	for(int i = 1;i <= tt;i ++) scanf("%d",&s);
	for(int i = 1;i <= tt;i ++) scanf("%d",&t);
	for(int i = 1;i <= m;i ++)
	{
		int u,v,w1,w2;
		scanf("%d%d%d%d",&u,&v,&w1,&w2);
		add(u,v,w1);
		add(v,u,w2);
	}
	int ans = 0;
	dijkstra(ss);
	ans += dis[s];
	dijkstra(s);
	printf("%d",ans + dis[t]);
	return 0;
}
