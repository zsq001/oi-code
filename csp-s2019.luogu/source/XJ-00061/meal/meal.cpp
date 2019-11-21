#include <cstdio>
int a[110][2019];
int main()
{
	int i,j,i1,i2,j1,j2,n,m;
	long long ans=0;
	freopen("meal.in","r",stdin);
	freopen("meal.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;i++)
		for(j=1;j<=m;j++)
			scanf("%d",&a[i][j]);
	for(i=1;i<=n;i++)
		for(j=1;j<=m;j++)
			for(i1=i;i1<=n;i1++)
			{
				if(i1==i)continue;
				for(j1=1;j1<=m;j1++)
				{
					if(j1==j)continue;
					ans=ans+a[i][j]*a[i1][j1];
				}
			}
	for(i=1;i<=n;i++)
		for(j=1;j<=m;j++)
			for(i1=i;i1<=n;i1++)
			{
				if(i1==i)continue;
				for(j1=1;j1<=m;j1++)
				{
					if(j1==j)continue;
					if(i1==i&&j1<=j)continue;
					for(i2=i1;i2<=n;i2++)
					{
						if(i2==i1||i2==i)continue;
						for(j2=1;j2<=m;j2++)
						{
							if(j2==j1||j2==j)continue;
							ans=ans+a[i][j]*a[i1][j1]*a[i2][j2];
						}
					}	
				}
			}
	ans=ans%998244353;
	printf("%lld",ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
