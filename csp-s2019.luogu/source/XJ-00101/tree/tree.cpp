#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int f[2005][2005];
int main()
{
	freopen("tree.in","r",stdin);
	freopen("tree.out","w",stdout);
	int t,n,i,j,k,a[2005],x,y;
	scanf("%d",&t);
	while(t--)
	{
		memset(a,0,sizeof(a));
		memset(a,0,sizeof(f));
		scanf("%d",&n);
		for(i=1;i<=n;i++)
		{
			scanf("%d",&a[i]);
		}
		for(i=1;i<n-1;i++)
		{
			scanf("%d%d",&x,&y);
			f[x][y]=1;
			f[y][x]=1;
		}
		for(i=1;i<=n;i++)
		{
			printf("%d ",a[i]);
		}
	}
	return 0;
}
