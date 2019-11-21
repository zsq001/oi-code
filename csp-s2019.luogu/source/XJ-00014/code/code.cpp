#include <stdio.h>
long long n,k;
long long f[64];
int main()
{
	freopen("code.in","r",stdin);
	freopen("code.out","w",stdout);
	scanf("%lld %lld",&n,&k);
	long long int a=1;
	for(long long i=1;i<=n;i++)a*=2;
	for(long long i=1;i<=k;i++)
	{
		long long q=i%4,p=int(i/4);//2+p%4
		if(q==1||q==3)f[n]=1-f[n];
		else if(q==2) f[n-1]=1-f[n-1];
		else
		{
			if(p%2==1)f[n-2]=1-f[n-2];
			else      f[n-1-p%(n-1)]=1-f[n-1-p%(n-1)];
		}
	}
	for(long long i=1;i<=n;i++)
	{
		printf("%lld",f[i]);
	}
	return 0;
}
