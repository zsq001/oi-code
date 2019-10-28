#include<stdio.h>
#include<stdlib.h>
int cf[1010][1010],n,m,x1,y1,x2,y2,t;
int main()
{
	freopen("carpet.in","r",stdin);
	freopen("carpet.out","w",stdout);
	int i,j;
	scanf("%d%d",&n,&m);
	for(i=1;i<=m;i++)
	{
		scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
		for(j=x1;j<=x2;j++)
		{
			cf[j][y1]++;
			cf[j][y2+1]--;
		}
	}
	for(i=1;i<=n;i++)
	{
		t+=cf[i][1]+cf[i-1][n+1];
		printf("%d ",t);
		for(j=2;j<=n;j++)
		{
			t+=cf[i][j];
			printf("%d ",t);
		}
		printf("\n");
	}
	return 0;
}
