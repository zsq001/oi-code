#include <stdio.h>
#include <math.h>
int mod=pow(10,9)+7;
int main()
{
	//freopen ("coordinate.in","r",stdin);
	//freopen ("coordinate.out","w",stdout);
	int n;
	scanf ("%d",&n);
	long long a=1,b=1,c=1;
	for (int i=1;i<n;i++)
	{
	   a=a+b+c;
	   b=a-b;
	   c=b%mod;
	   a=a%mod;
	   b=c;
	}
	int ans=(a%mod+b%mod+c%mod)%mod;
	printf ("%d",ans);
}
