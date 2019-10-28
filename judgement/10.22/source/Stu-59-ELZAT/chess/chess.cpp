#include<cstdio>
#include<algorithm>
#include<stack>
using namespace std;
int n,m,flag,mp[55][55];
char s[55];
int dfn[2510],low[2510],vis[2510],cnt,tot,num[2510];
stack<int>S;

struct edge{
	int v,next;
}e[50010];
int head[2510];

void add(int u,int v)
{
	e[++cnt].v = v;
	e[cnt].next = head[u];
	head[u] = cnt;
}

void BUILD()
{
	for(int i = 1;i <= n;i ++)
	{
		for(int j = 1;j <= m;j ++)
		{
			if(mp[i][j-1] == mp[i][j]) add(m*(i-1)+j,m*(i-1)+j-1);
			if(mp[i][j+1] == mp[i][j]) add(m*(i-1)+j,m*(i-1)+j+1);
			if(mp[i-1][j] == mp[i][j]) add(m*(i-1)+j,m*(i-2)+j);
			if(mp[i+1][j] == mp[i][j]) add(m*(i-1)+j,m*(i)+j);
		}
	}
}

void tarjan(int x,int fa)
{
	dfn[x] = low[x] = ++cnt;
	vis[x] = 1;
	S.push(x);
	for(int i = head[x];i;i = e[i].next)
	{
		int v = e[i].v;
		if(!dfn[v])
		{
			tarjan(v,x);
			low[x] = min(low[x],low[v]);
		}
		else if(v != fa) low[x] = min(low[x],dfn[v]);
	}
	if(dfn[x] == low[x])
	{
		int now = -1;
		tot ++;
		while(now != x)
		{
			now = S.top();
			S.pop();
			num[tot] ++;
			vis[now] = 0;
		}
		if(num[tot] >= 4)
		{
			flag = 1;
			return;
		}
	}
}

void PRINT()
{
	for(int i = 0;i <= n+1;i ++)
	{
		for(int j = 0;j <= m+1;j ++)
		{
			printf("%d ",mp[i][j]);
		}
		puts("");
	}
}

int main()
{
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i = 1;i <= n;i ++)
	{
		scanf("%s",s+1);
		for(int j = 1;j <= m;j ++)
		{
			mp[i][j] = s[j] - 'A' + 1;
		}
	}
//	PRINT();
	BUILD();
	cnt = 0;
	for(int i = 1;i <= n*m;i ++)
	{
		if(!dfn[i]) tarjan(i,i);
		if(flag) break;
	}
	puts(flag?"Yes":"No");
	return 0;
}
