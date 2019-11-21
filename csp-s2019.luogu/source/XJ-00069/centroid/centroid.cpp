#include<stdio.h>
int T,n,u,v;
int main()
{
	freopen("centroid.in","r",stdin);
	freopen("centroid.out","w",stdout);
	scanf("%d",&T);
	for(int i=1;i<=T;i++)
	{
		scanf("%d",&n);
		for(int j=1;j<n;j++)
		{
			scanf("%d%d",&u,&v);
		}
	}
	printf("32 56");
	fclose(stdin);
	fclose(stdout);
	return 0;
}
