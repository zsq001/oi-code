#include<stdio.h>
int h[1004][2],z[1004][2];
int main()
{
	freopen("matrix.in","r",stdin);
	freopen("matrix.out","w",stdout);
	int n,m,q;
	scanf("%d%d%d",&n,&m,&q);
	for(int i=1;i<=q;i++)
	{
		int x,y,zz;
		scanf("%d%d%d",&x,&y,&zz);
		if(x==1)
		{
			h[y][0]=zz;
			h[y][1]=i;
		}
		else
		{
			z[y][0]=zz;
			z[y][1]=i;
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
			if(h[i][1]>=z[j][1]) printf("%d ",h[i][0]);
			else printf("%d ",z[j][0]);
		printf("\n");
	}
	return 0;
}
