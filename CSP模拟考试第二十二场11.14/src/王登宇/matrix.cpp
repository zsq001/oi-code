#include<stdio.h>
int k[1010][1010],a,b,c,n,m,num;
int main()
{
	freopen("matrix.in","r",stdin);
	freopen("matrix.out","w",stdout);
	scanf("%d%d%d",&n,&m,&num);
	for(int i=1;i<=num;i++)
	{
		scanf("%d%d%d",&a,&b,&c);
		if(a==1)
		{
			for(int j=1;j<=m;j++)
			k[b][j]=c;
		}
		else 
		{
			for(int j=1;j<=n;j++)
			k[j][b]=c;
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		printf("%d ",k[i][j]);
		printf("\n");
	}
	fclose(stdin);
	fclose(stdout);
}
