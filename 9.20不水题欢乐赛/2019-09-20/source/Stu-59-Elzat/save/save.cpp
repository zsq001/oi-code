#include<cstdio>
int n,k,s,t;
struct edge{
	int u,v,w,next;
}e[1000];
int head[20],cnt;
int vis[20],flag,mp[20][20],ans,bns;

void add(int u,int v,int w)
{
	e[++cnt].u = u;
	e[cnt].v = v;
	e[cnt].w = w;
	e[cnt].next = head[u];
	head[u] = cnt;
}

void dfs(int x,int fa,int num,int sum)
{
	if(num == n)
	{
		if(bns > sum + mp[x][t]) bns = sum + mp[x][t];
		flag = true;
		return;
	}
	if(vis[x]) return;
	vis[x] = 1;
	for(int i = head[x];i;i = e[i].next)
	{
		int v = e[i].v;
		if(v == fa) continue;
		dfs(v,x,num+1,sum + e[i].w);
	}
	
}


int main()
{
	freopen("save.in","r",stdin);
	freopen("save.out","w",stdout);
	scanf("%d%d",&n,&k);
	s = 0;t = n + 1; 
	for(int i = 1;i <= n;i ++)
	{
		int w;
		scanf("%d",&w);
		mp[s][i] = w;
	}
	for(int i = 1;i <= n;i ++)
	{
		int w;
		scanf("%d",&w);
		mp[i][t] = w;
	}
	for(int i = 1;i <= n;i ++)
	{
		for(int j = 1;j <= n;j ++)
		{
			int w;
			scanf("%d",&w);
			if(i != j)
				add(i,j,w);
		}
	}
	for(int k = 1;k <= n;k ++)
	for(int i = 1;i <= 5;i ++)
	{
		for(int j = 1;j <= 5;j ++)
		{
			int x;
			scanf("%d",&x);
		}
	}
	int ANS = 0x3f3f3f3f;
	for(int i = 1;i <= n;i ++)
	{
		ans = mp[s][i];
		bns = 0x3f3f3f3f;
		dfs(i,i,1,0);
		if(flag && ANS > ans + bns) ANS = ans + bns;
	}
	if(flag)
	{
		printf("YES\n%d",ANS);
	}
	else
	{
		puts("NO");
	}
	return 0;
}
