#include<cstdio>
#include<algorithm>
#include<cmath>
typedef int int_;
#define int long long
using namespace std;
int n,a,b,c,mi,now,flag;
bool su(int x)
{
	for(int i=2;i*i<=n;i++)
	{
		if(x%i==0)
		{
			return false;
		}
	}	
	return true;
}
int_ main()
{
	freopen("box.in","r",stdin);
	freopen("box.out","w",stdout);
	scanf("%lld",&n);
	mi=3;
	now=2;
	if(su(n))
	{
		printf("%lld",2+4*n);
	}
	else
	{
		while(now*now*now<=n)
		{
			if(n%now==0)
			{
				flag=now;
				if(now*now*now==n)
				{
					printf("%lld",6*now*now);
					return 0;
				}
			}
			now++;
		}
		a=flag;
		n/=a;
		if(su(n))
		{
			printf("%lld",2*a*n+2*n+2*a);
			return 0;
		}
		now=2;
		while(now*now<=n)
		{
			if(n%now==0)
			{
				flag=now;
			}
			now++;
		}
		b=flag;
		c=n/flag;
		printf("%lld",2*a*b+2*a*c+2*b*c);
		return 0;
	}
}

