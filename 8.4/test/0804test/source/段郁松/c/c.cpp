#include<stdio.h>
#define ll long long int
ll n,m,k,num=214748364;
ll a[1050000];
void work(ll x,ll k,ll maxn)
{
	ll i;
	if(x==n&&maxn<num)
	{
		num=maxn;
		return ;
	}
	if(x>n)
	{
		return ;
	}
	for(i=1;i<=k;++i)
	{
		if(a[i+x]>=a[x])
		{
			work(x+i,k,maxn+1);
		}
		else 
		{
			work(x+i,k,maxn);
		}
	}
}
int main()
{
	freopen("c.in","r",stdin);
	freopen("c.out","w",stdout);
	ll i;
	scanf("%lld",&n);
	for(i=1;i<=n;++i)
	{
		scanf("%lld",&a[i]);
	}
	scanf("%lld",&m);
	while(m--)
	{
		scanf("%lld",&k);
		work(1,k,0);
		if(num==214748364)
		{
			printf("0\n");
		}
		else
		{
			printf("%lld\n",num);
		}	
		num=214748364;
	}
	return 0;
}
