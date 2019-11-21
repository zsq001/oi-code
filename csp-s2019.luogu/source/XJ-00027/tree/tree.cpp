#include <bits/stdc++.h>

using namespace std;

int main()
{
	freopen("tree.in","r",stdin);
	freopen("tree.out","w",stdout);
	int t,ans=2147483647;
	scanf("%d",&t);
	for(int i=1;i<=t;i++)
	{
		int a[5000],ansi;
		int n,x,y;
		scanf("%d",&n);
		for(int j=1;j<=n;j++)
			scanf("%d",&a[j]);
		for(int j=1;j<=n-1;j++)
			scanf("%d %d",&x,&y);
		for(int j=1;j<=n;j++)
		{
			ans=2147483646;
			for(int k=1;k<=n;k++)
			{
				if(a[k]<ans)
				{
					ansi=k;
					ans=a[k];
				}
			}
			printf("%d ",ans);
			a[ansi]=2147483647;
		}
		printf("\n");
	}
	return 0;
}

