#include<cstdio>
typedef int int_;
#define int long long
const int MOD = 1e9+7;

int ksm(int a,int b)
{
	int ret = 1;
	while(b)
	{
		if(b&1)
		{
			ret = (1ll * ret * a) % MOD;
		}
		b >>= 1;
		a = (1ll * a * a) % MOD;
	}
	return ret;
}

int_ main()
{
	freopen("magic.in","r",stdin);
	freopen("magic.out","w",stdout);
	int n;
	scanf("%lld",&n);
	int ans = ksm(3,n+1);
	printf("%lld",1ll * (ans-1ll) * (500000004ll) % MOD);
	return 0;
}
