#include<stdio.h>
#include<stdlib.h>
#define mo 100000007
typedef long long ll;
bool a[mo];
ll ans,n;
int main()
{
	freopen("water.in","r",stdin);
	freopen("water.out","w",stdout);
	ll i,j;
	ans=1;
	scanf("%lld",&n);
	for(i=2;i<=n;++i)
	{
		if(!a[i])
		{
			for(j=i*i;j<=n;j+=i)
			{
				a[j]=true;
			}
		}
	}
	for(i=2;i<=n;i++)
	{
		if(!a[i])
		{
			j=1;
			while(j*i<=n)
			{
				j*=i;
				ans*=i;
				ans%=mo;
			}
		}
	}
	printf("%lld",ans);
	return 0;
}
