#include<stdio.h>
int a[10001],b[10001],ans[10001];
int main()
{
	freopen("centroid.in","r",stdin);
	freopen("centroid.out","w",stdout);
	int n,i,j,t;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%d",&t);
		for(j=1;j<t;j++)
		{
			scanf("%d%d",&a[j],&b[j]);
		}
	}
	for(i=1;i<=n;i++)
	{
		printf("%d\n",ans[i]);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
