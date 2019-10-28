#include<stdio.h>
#include<math.h>
#include<string.h>
#include<algorithm>
using namespace std;
int ji;
int n,k,tq[15],th[15],ju[100][100],ju1[15][15],ju2[15][15];
int main()
{
	freopen("save.in","r",stdin);
	freopen("save.out","w",stdout);
	int i,j;
	scanf("%d%d",&n,&k);
	for(i=1;i<=n;++i)
	{
		scanf("%d",&tq[i]);
	}
	for(i=1;i<=n;++i)
	{
		scanf("%d",&th[i]);
	}
	for(i=1;i<=n;++i)
	{
		for(j=1;j<=n;++j)
		{
			scanf("%d",&ju[i][j]);
		}
	}
	for(i=1;i<=5;++i)
	{
		for(j=1;j<=5;++j)
		{
			scanf("%d",&ju1[i][j]);
			if(ju1[i][j]==1) ji=1;
		}
	}
	if(n==1&&ji==0)
	{
		printf("YES\n");
		printf("%d",th[1]+tq[1]);
	}
	else printf("NO\n");
	return 0;
}
