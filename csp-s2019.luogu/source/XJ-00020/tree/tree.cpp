#include <stdio.h>
int a[100000];
int main()
{
	freopen("tree.in","r",stdin);
	freopen("tree.out","w",stdout);
	int n,T,x,y;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		for(int i=1;i<=n;i++)scanf("%d",&a[i]);
		for(int i=1;i<n;i++)scanf("%d%d",&x,&y);
		for(int i=1;i<n;i++)
		{
			int t=a[i];
			a[i]=a[i+1];
			a[i+1]=t;
		}
		for(int i=1;i<=n;i++)
			printf("%d ",a[i]);
		puts("");
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
	
