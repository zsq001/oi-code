#include<cstdio>
#include<queue>
#include<vector>
using namespace std;
const int inf = 0x3f3f3f3f;
int a[100010];
int n,m,s,t,ans;
//vector<int>v[200010];
struct edge{
	int v,w,next;
}e[100000010];
int cnt = 1,head[200010],late[200010];
int dis[200010];
void add(int u,int v,int w)
{
	e[++cnt].v = v;
	e[cnt].w = w;
	e[cnt].next = head[u];
	head[u] = cnt;
	
	e[++cnt].v = u;
	e[cnt].w = 0;
	e[cnt].next = head[v];
	head[v] = cnt;
}

bool bfs()
{
	for(int i = 0;i <= n+m+1;i ++) dis[i] = inf;
	queue<int>Q;
	dis[s] = 0;
	Q.push(s);
	while(!Q.empty())
	{
		int x = Q.front();
		Q.pop();
		for(int i = head[x];i;i = e[i].next)
		{
			int v = e[i].v;
			if(e[i].w && dis[v] > dis[x] + 1)
			{
				dis[v] = dis[x] + 1;
				Q.push(v);
			}
		}
		
	}
	return dis[t] < inf;
}

int dfs(int x,int water)
{
	if(x == t) return water;
	for(int i = late[x];i;i = e[i].next)
	{
		late[x] = i;
		int v = e[i].v;
		if(e[i].w && dis[v] == dis[x] + 1)
		{
			int k = min(e[i].w,water);
			int flow = dfs(v,k);
			if(flow)
			{
				e[i].w -= flow;
				e[i^1].w += flow;
				return flow;
			}
		}
	}
}

void dinic()
{
	while(bfs())
	{
		for(int i = 0;i <= n+m+1;i ++) late[i] = head[i];
		int flow = dfs(s,inf);
		while(flow)
		{
			
			ans += flow;
			flow = dfs(s,inf);
		}
	}
}

int main()
{
	freopen("match.in","r",stdin);
	freopen("match.out","w",stdout);
	int x,y;
	scanf("%d%d%d%d",&n,&m,&x,&y);
	s = 0;t = n+m+1;
	for(int i = 1;i <= n;i ++)
	{
		scanf("%d",&a[i]);
	}
	for(int i = 1;i <= m;i ++)
	{
		int b;
		scanf("%d",&b);
		for(int j = 1;j <= n;j ++)
		{
			if(a[j] - x > b) break;
			if(a[j] + y < b) continue;
			if(!head[i])add(s,i,1);
			if(!head[j+m])add(j+m,t,1);
			add(i,j+m,inf);
//			v[i].push_back(j+m);
//			v[j+m].push_back(i);
		}
	}
	dinic();
	printf("%d",ans);
	return 0;
}
