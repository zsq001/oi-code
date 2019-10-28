#include<stdio.h>
#include<stdlib.h>
#define min(a,b) a<b?a:b
#define max(a,b) a>b?a:b
int a[111],tong[5];
int main()
{
	freopen("a.in","r",stdin);
	freopen("a.out","w",stdout);
	int t,n,i,j,x,alr,ans,large,small;
	scanf("%d",&t);
	for(i=1;i<=t;i++)
	{
		ans=0;
		tong[0]=0;
		tong[1]=0;
		tong[2]=0;
		scanf("%d",&n);
		for(j=1;j<=n;j++)
		{
			scanf("%d",&x);
			tong[x%3]++;
		}
		large=max(tong[1],tong[2]);
		small=min(tong[1],tong[2]);
		ans=tong[0]+small+(large-small)/3;
		printf("%d\n",ans);
	}
	return 0;
}
