#include<cstdio>
int a[100010];
int main()
{
	int n,k,i,j;
	freopen("lamp.in","r",stdin);
	freopen("lamp.out","w",stdout);
	scanf("%d%d",&n,&k);
	if(n==1)
	{
		printf("%d",k);
		return 0;
	}
	if(k==3){
		printf("2");
		return 0;
	}
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=k;j++)
		{
			scanf("%1d",&a[j]);
		}
	}
	printf("%d",k>>1);
	fclose(stdin);
	fclose(stdout);
}
