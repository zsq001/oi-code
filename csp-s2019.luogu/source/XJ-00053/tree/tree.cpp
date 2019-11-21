#include<stdio.h>
int main()
{
	int n,m,i,j,a,b;
	int x[2001];	
	freopen("tree.in","r",stdin);
	freopen("tree.out","w",stdout);
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%d",&m);
		for(j=1;j<=m;j++)
		{
			scanf("%d",&x[j]);
			printf("%d ",x[j]);
		}	
		for(j=1;j<m;j++)
			scanf("%d %d",&a,&b);		
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
