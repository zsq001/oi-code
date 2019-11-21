#include<stdio.h>
#include<algorithm>
#include<string.h>
#include<math.h>
using namespace std;
struct edge
{
	int to,nxt;
	bool zt;
}e[20010];
int eHead[10010],ecnt;
void addedge(int a,int b)
{
	ecnt++;
	e[ecnt].to = b;
	e[ecnt].nxt = eHead[a];
	eHead[a] = ecnt;
	e[ecnt].zt = 1;
}
bool vis[10010];
int son[100][10010],ts;
int findson(int a)
{
	vis[a] = true;
	int stot = 0;
	for(int i = eHead[a];i;i = (e[i].zt ? e[i].nxt : e[e[i].nxt].nxt))
		if(!vis[e[i].to])
		{
			int s = findson(e[i].to);
			son[e[i].to][a] += s;
			stot += s;
		}
	son[99][a] = stot;
	return stot;
}
int main()
{
	freopen("centroid.in","r",stdin);
	freopen("centroid.out","w",stdout);
	int T,n;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		for(int i = 1;i < n;i++)
		{
			int x,y;
			scanf("%d%d",&x,&y);
			addedge(x,y);addedge(y,x);
		}
		int ans = 0;
		for(int i = 1;i < n * 2 - 1;i += 2)
		{
			memset(vis,0,sizeof(vis));
			memset(son,0,sizeof(son));
			e[i].zt = e[i + 1].zt = false;
			findson(1);
			for(int j = 1;j <= n;j++)
			{
				if(vis[j])
				{
					int maxn = 0,flg = 0;
					for(int k = 1;k < n;k++)
					{
						maxn = max(maxn,son[k][j]);
						if(maxn > son[99][j])
						{
							flg = 1;
							break;
						}
					}
					if(flg == 0)
						ans += j;
				}
			}
			int nt = 0;
			for(int i = 1;i <= n;i++)
				if(!vis[i])
					nt = i;
			memset(vis,0,sizeof(vis));
			findson(nt);
			for(int j = 1;j <= n;j++)
			{
				if(vis[j])
				{
					int maxn = 0,flg = 0;
					for(int k = 1;k < n;k++)
					{
						maxn = max(maxn,son[k][j]);
						if(maxn > son[99][j])
						{
							flg = 1;
							break;
						}
					}
					if(flg == 0)
						ans += j;
				}
			}
			e[i].zt = e[i + 1].zt = true;
		}
		printf("%d\n",ans);
	}
	return 0;
}
