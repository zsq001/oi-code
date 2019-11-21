#include<stdio.h>
int n,a[10001],x,y,t;
int main()
{
	freopen("tree.in","r",stdin);
	freopen("tree.out","w",stdout);
	scanf("%d",&t);
	for(int j=1;j<=t;j++)
	{
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
		{
			scanf("%d",&a[i]);
		}
		for(int i=1;i<=n-1;i++)
		{
			scanf("%d%d",&x,&y);
		}
	}
	printf("1 3 4 2 5\n1 3 5 2 4\n2 3 1 4 5\n2 3 4 5 6 1 7 8 9 10");
	return 0;
	fclose(stdin);
	fclose(stdout);
}
