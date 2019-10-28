#include <stdio.h>
int a[10000],n,m;
int rand(int x)
{
	return (x*1927317+1089113)%n;
}
int main()
{
	freopen("a.in","r",stdin);
	freopen("a.out","w",stdout);
	scanf("%d%d",&n,&m);
	if(m*2>n)
	{
		printf("Error!\n");
		return 0;
	}
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	int ans=0;
	for(int i=1;i<=m;i++)	
	{
		ans+=a[rand(i)];
	}
	printf("%d\n",ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}		
