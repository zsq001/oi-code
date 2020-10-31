#include <stdio.h>
int map[210][210],vis[210];
#define M 1000000000
int main()
{
	//freopen ("calabash.in","r",stdin);
	//freopen ("calabash.out","w",stdout);
	int n,m;
	scanf ("%d %d",&n,&m);
	int i,j,v;
	int k=0;
	for (i=1;i<=n;i++)
	{
		for (j=1;j<=n;j++)
		{
			map[i][j]=M;
		}
	}
	for (i=1;i<=m;i++)
	{
		int u,v,w;
		scanf("%d %d %d",&u,&v,&w);
		map[u][v]=w;
	}
	for (v=1;v<=n;v++)
	{
		for (i=1;i<=n;i++)
		{
			for (j=1;j<=n;j++)
			{
				if (map[i][v]+map[v][j]<map[i][j]) map[i][j]=map[i][v]+map[v][j],vis[j]=v,vis[v]=i;
			}
		}
	}
	int nn=n;
	while (vis[nn]!=0)
	{
		nn=vis[nn];
		k++;
	}
	float ans=map[1][n]/(k+1);
	printf ("%.3f",ans);
}
