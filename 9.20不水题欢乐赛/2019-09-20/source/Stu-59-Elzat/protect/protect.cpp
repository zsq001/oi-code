#include<cstdio>
#include<cmath>
const double eps = 1e-9;
int n;
double x[10],y[10],dis[10][10],r[10],ans;

double dist(int u,int v)
{
	return sqrt((x[u] - x[v])*(x[u] - x[v])+(y[u] - y[v])*(y[u] - y[v]));
}

void init()
{
	for(int i = 1;i <= n;i ++)
	{
		for(int j = 1;j <= n;j ++)
		{
			if(!dis[i][j] && i != j)
			{
				dis[i][j] = dist(i,j);
			}
//			printf("%lf ",dis[i][j]);
		}
//		puts("");
	}
}

void dfs(int cur,double sum)
{
	if(cur > n)
	{
		if(ans < sum) ans = sum;
		return;
	}
	double minr = 1e9;
	for(int i = 1;i <= n;i ++)
	{
		if(cur == i) continue;
		if(minr > dis[cur][i] - r[i]) minr = dis[cur][i] - r[i];
	}
	r[cur] = minr;
	dfs(cur+1,sum+minr*minr);
	r[cur] = 0;
	dfs(cur+1,sum);
}

int main()
{
	freopen("protect.in","r",stdin);
	freopen("protect.out","w",stdout);
	scanf("%d",&n);
	for(int i = 1;i <= n;i ++)
	{
		scanf("%lf%lf",&x[i],&y[i]);
	}
	init();
	dfs(1,0);
	printf("%.2lf",ans);
	return 0;
}
