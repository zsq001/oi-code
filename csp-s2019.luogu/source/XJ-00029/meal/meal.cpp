#include<stdio.h>
#define N 998244353
int a[101][101];
int main()
{
	freopen("meal.in","r",stdin);
	freopen("meal.out","w",stdout);
	int n,m,i,j,ans=0;
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=m;j++)
		{
			scanf("%d",&a[i][j]);
		}
	}
	if(n==2&&m==2)
	{
		if(a[1][1]>a[2][2]) a[1][1]=a[2][2];
		if(a[1][2]>a[2][1]) a[1][2]=a[2][1];
		printf("%d",(a[1][1]+a[1][2])%N);
	}
	if(n==2&&m==3)
	{
		for(i=1;i<=3;i++)
		{
			for(j=1;j<=3;j++)
			{
				if(j==i) continue;
				if(a[1][i]<a[2][j]) ans+=a[1][i];
				else ans+=a[2][j];
			}
		}
		printf("%d",ans%N);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
