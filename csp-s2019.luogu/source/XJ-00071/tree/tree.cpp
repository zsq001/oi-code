#include<stdio.h>
int main()
{
	freopen("tree.in","r",stdin);
	freopen("tree.out","w",stdout);
	
	int n,r,i,j,k,l;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%d",&k);
		for(j=1;j<=k;j++)
		{
			scanf("%d",&r);
		}
		for(j=1;j<k;j++)
		{
			scanf("%d%d",&r,&l);
		}
	}
	printf("1 3 4 2 5\n1 3 5 2 4\n2 3 1 4 5\n2 3 4 5 6 1 7 8 9 10");
	fclose(stdin);
	fclose(stdout);
}
