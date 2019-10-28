#include<stdio.h>
#include<stdlib.h>
#define mo 19260817
long long calc(long long n)
{
	if(n==1)
	{
		return 2;
	}
	long long t=calc(n/2);
	if(n%2==0)
	{
		return t*t%mo;
	}
	else
	{
		return t*t%mo*2%mo;
	}
}
int main()
{
	freopen("pcr.in","r",stdin);
	freopen("pcr.out","w",stdout);
	long long n;
	scanf("%lld",&n);
	printf("%lld",(calc(n)+mo-(2*n)%mo)%mo);
	return 0;
}
