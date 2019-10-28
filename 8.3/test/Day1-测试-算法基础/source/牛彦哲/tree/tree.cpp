#include<stdio.h>
int main()
{
	freopen("tree.in","r",stdin);
	freopen("tree.out","w",stdout);
	long long n,p=1,ans=0;
	scanf("%lld",&n);
	while(p<=n)
	{
		p*=2;
		ans++;
	}
	printf("%lld",ans);
	return 0;
}
