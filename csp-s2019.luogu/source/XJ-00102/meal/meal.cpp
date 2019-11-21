#include<bits/stdc++.h>
using namespace std;
int n,m,k=1,i,j,d,s;
long long int a[100][1000];
int main()
{
	freopen("meal.in","r",stdin);
	freopen("meal.out","w",stdout);
	scanf("%d %d",&n,&m);
	for(i=1;i<=n;i++)
	{
		scanf("%c",&d);
		for(j=1;j<=m;j++)
		{
		scanf("%lld",&a[i][j]);
	    }
	}
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=i;j++)
		{
			if(a[i][j]!=a[i+1][j]&&a[i][j]<=m/2) k++;
		}
	}
	printf("%d",k%998244353);
	return 0;
	fclose(stdin);
	fclose(stdout);
}
