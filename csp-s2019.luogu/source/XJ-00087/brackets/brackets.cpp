#include<cstdio>
int n;
char s[2010];

struct edge{
	int v,next;
}e[2010];
int head[2010],cnt,fa[2010],len,cls[2010],dp[2010];
char t[2010];

void add(int u,int v)
{
	e[++cnt].v = v;
	e[cnt].next = head[u];
	head[u] = cnt;
}

int st[2010],top;


void dfs(int x)
{
	for(int i = head[x];i;i = e[i].next)
	{
		int v = e[i].v;
//		t[++len] = s[v];
//		work(len);
		dfs(v);
		if(s[x] == '(')
		{
			cls[x] += cls[v];
			if(s[v] == ')') cls[x] --,dp[x] ++;
			else dp[x] += cls[v];
		}
		dp[x] += dp[v];
		
//		len --;
	}
	if(s[x] == ')') cls[x] = 1;
}

int main()
{
	freopen("brackets.in","r",stdin);
	freopen("brackets.out","w",stdout);
	scanf("%d",&n);
	scanf("%s",s+1);
	for(int i = 1;i < n;i ++)
	{
		int x;
		scanf("%d",&x);
		add(x,i+1);
		fa[i+1] = x;
	}
	dfs(1);
	printf("%d",dp[1]);
	
	fclose(stdin);
	fclose(stdout);
	
	return 0;
}
