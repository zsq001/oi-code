#include<stdio.h>
#include<stdlib.h>
#include<cmath>
#include<algorithm>
int a[105][2005],f[105],ans,f2[2005];
int main()
{
	int i,j,k,n,m,x,y;
	freopen("meal.in","r",stdin);
	freopen("meal.out","w",stdout);
	scanf("%d %d",&n,&m);
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=m;j++)
		{
			scanf("%d",&a[i][j]);
		}
	}
	for(x=1;x<=n;x++)
	{
		for(y=1;y<=m;y++)
		{
			if(a[x][y]!=0)
			{
				f[y]++;
				for(j=x+1;j<=n;j++)
				{
					for(k=1;k<=m;k++)
					{
						if(f[k]<n/2) ans=ans+a[x][y]*a[j][k];
					}
				}
				f[y]--;			
			}

		}

	}
	printf("%d",ans);
	return 0;
}
