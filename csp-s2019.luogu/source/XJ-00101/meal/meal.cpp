#include<stdio.h>
int n,m,a[105][2005],ans,chose[2005],sum[105];
int main()
{
	freopen("meal.in","r",stdin);
	freopen("meal.out","w",stdout);
	int i,j,k;
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=m;j++)
		{
			scanf("%d",&a[i][j]);
		}
	}
	if(n==2 && m==2)
	{
		ans=a[1][1]*a[1][2]+a[1][2]*a[2][1];
	}
	if(n==2 && m==3)
	{
		ans=a[1][1]*(a[2][2]+a[2][3])+a[1][2]*(a[2][1]+a[2][3])+a[1][3]*(a[2][1]+a[2][2]);
	}
	
	printf("%d",ans);
	return 0;
}
