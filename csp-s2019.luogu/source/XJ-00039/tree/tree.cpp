#include <stdio.h>
int main()
{
	int n,b,ans,t,u,v;
	freopen("tree.in","r",stdin);
	freopen("tree.out","w",stdout);
	scanf("%d",&t);
	for(int i=1;i<=t;i++)
	{
	   scanf("%d",&n);
	   for(int j=1;j<=n;j++)
	   scanf("%d",&b);
	   for(int j=1;j<n;j++)
	   scanf("%d%d",&u,&v);
	   for(int j=1;j<=n;j++)
	   printf("%d",j);
}
return 0;
}
