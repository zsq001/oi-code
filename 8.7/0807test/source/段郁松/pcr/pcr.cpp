#include<stdio.h>
long long int a1,a2,b1,b2,c1,c2;
long long int n;
int main()
{
	freopen("pcr.in","r",stdin);
	freopen("pcr.out","w",stdout);
	long long int i;
	a1=2;
	b1=0;
	c1=0;
	scanf("%lld",&n);
	for(i=1;i<=n;++i)
	{
		if(i==1) continue;
		b2=(a1+b1)%19260817;
		c2=(c1*2+b1)%19260817;
		b1=b2;
		c1=c2;
	}
	printf("%lld",c2);
	return 0;
}
