#include <stdio.h>
struct node
{
	int x,y;
}a[1000002];
int main()
{
	int T,n;
	freopen("centroid.in","r",stdin);
	freopen("centroid.out","w",stdout);
	scanf("%d",&T);
	while(T--)
	{
		int max=0,ans=0;
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
		{
			scanf("%d %d",&a[i].x,&a[i].y);
			if(a[i].x>max) max=a[i].x;
			if(a[i].y>max) max=a[i].y;
		}
		for(int i=1;i<=max;i++)
		  ans+=i;
		printf("%d\n",ans*2);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
