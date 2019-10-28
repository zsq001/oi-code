#include <stdio.h>
#include <algorithm>
using namespace std;
const int max1=1005;
int a[max1],b[max1],c[max1],d[max1];
int main()
{
	int n,m,k,x,s;
	freopen("sword.in","r",stdin);
	freopen("sword.out","w",stdout);
	scanf("%d%d%d%d%d",&n,&m,&k,&x,&s);
	if(m<=1000&&k<=1000)
	{
		long long ans=(long long)n*x;
		for(int i=1;i<=m;i++)
		{
			scanf("%d",&a[i]);	
		}
		for(int i=1;i<=m;i++)
		{
			scanf("%d",&b[i]);
		}	
		for(int i=1;i<=k;i++)
		{
			scanf("%d",&c[i]);
		}
		for(int i=1;i<=k;i++)
		{
			scanf("%d",&d[i]);
		}
		for(int i=1;i<=m;i++)
			for(int j=1;j<=k;j++)
			{
				if(s>=(b[i]+d[j]))ans=min(ans,(long long)((n-c[j])*a[i]));
				else if(s>=b[i])ans=min(ans,(long long)(n*a[i]));
				else if(s>=d[j])ans=min(ans,(long long)((n-c[j])*x));
			}
		printf("%lld",ans);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
