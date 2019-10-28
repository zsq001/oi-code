#include <stdio.h>
int ans[2005][2005];
int main()
{
	int n,m,a1,a2,b1,b2;
	freopen("carpet.in","r",stdin);
	freopen("carpet.out","w",stdout);
	scanf("%d%d",&n,&m);
	while(m--)
	{
		scanf("%d%d%d%d",&a1,&b1,&a2,&b2);
		for(int i=a1;i<=a2;i++)
			for(int j=b1;j<=b2;j++)
			{
				ans[i][j]++;
			}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
			printf("%d ",ans[i][j]);
		puts("");
	}
	return 0;
	fclose(stdin);
	fclose(stdout);
}
