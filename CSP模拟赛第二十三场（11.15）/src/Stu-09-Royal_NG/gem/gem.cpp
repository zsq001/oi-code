#include<stdio.h>
int a[300000];
int main()
{
	freopen("gem.in","r",stdin);
	freopen("gem.out","w",stdout);
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	for(int i=1;i<=m;i++)
	{
		int k;
		scanf("%d",&k);
		if(k==1)
		{
			int l,r,now=0,ans=0;
			scanf("%d%d",&l,&r);
			for(int j=l;j<r;j++)
			{
				if(a[j]<a[j+1]&&!now)
				{
					now=a[j];
				}
				else if(now&&a[j]>a[j+1])
				{
					ans+=a[j]-now;
					now=0;
				}
			}
			if(now)ans+=a[r]-now;
			printf("%d\n",ans);
		}
		else
		{
			int l,r,a1,d;
			scanf("%d%d%d%d",&l,&r,&a1,&d);
			a[l]=a1;
			for(int j=l+1;j<=r;j++)
				a[j]=a[j-1]+d;
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
