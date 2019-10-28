#include<stdio.h>
#include<string.h>
#include<algorithm>
#define mod 19260817 
using namespace std;

long long n,ms=2,ss=0;

long long pcr(long long a,long long n)
{
	long long b=1; 
	while(n>0)
	{
		if(n&1)
		{
			b=(a*b)%mod;
		}
		n>>=1;
		a=(a*a)%mod;
	}
	return b%mod;
}

int main()
{
	freopen("pcr.in","r",stdin);
	freopen("pcr.out","w",stdout);
	scanf("%lld",&n);
	printf("%lld\n",pcr(2,n)-(2*n)%mod);
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
