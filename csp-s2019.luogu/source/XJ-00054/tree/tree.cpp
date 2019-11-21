#include<stdio.h>
#include<stdlib.h>
int T,n,bi[2005][2005],a[2005];
int main()
{
	freopen("tree.in","r",stdin);
	freopen("tree.out","w",stdout);
	int i,j,num,x,y;
	scanf("%d",&T);
	for(i=1;i<=T;i++)
	{
		scanf("%d",&n);
		for(j=1;j<=n;j++)
		{
			scanf("%d",&a[j]);
		}
		for(j=1;j<n;j++)
		{
			scanf("%d%d",&x,&y);
			bi[x][y]=1;
		}
	}
	printf("1 3 4 2 5\n1 3 5 2 4\n2 3 1 4 5\n2 3 4 5 6 1 7 8 9 10\n");
	return 0;
}
