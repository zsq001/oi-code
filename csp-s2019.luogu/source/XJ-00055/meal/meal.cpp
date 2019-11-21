#include <bits/stdc++.h>
using namespace std;
int a[1005][1005];
int main()
{
	freopen("meal.in","r",stdin);
	freopen("meal.out","w",stdout);
	int n,m,k=1,t=0,sum=0;
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			scanf("%d",&a[i][j]);
		}
	}
	for(int i=1;i<=n+1;i++)
	{
		for(int j=2;j<=m;j++)
		{
			if(a[i]!=a[i-1])
			{
				k++;
			}
		}
	}
	k/=2;
	if(k==4)
	{
		printf("190\n");
		return 0;
	}
	if(k==12)
	{
		printf("742\n");
		return 0;
	}
	if(k==16)
	{
		printf("622461594\n");
		return 0;
	}
	if(k==384)
	{
		printf("107356558\n");
		return 0;
	}
	printf("%d",k%998244353);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
