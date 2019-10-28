#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
#define ll long long 
using namespace std;

//1*(1-3^(n+1))/1-3

ll n,ans;
ll p=1e9+7;

ll ksm(ll x,ll y,ll z)
{
	ll ret=1;
	while(y)
	{
		if(y&1) 
		{
			ret=(1ll*ret*x)%z;
		}
		x=(1ll*x*x)%z;
		y>>=1;
		
	}
	return ret;
}

	

int main()
{
	freopen("magic.in","r",stdin);
	freopen("magic.out","w",stdout);
	scanf("%lld",&n);
	ll an=ksm(3,n+1,p)%p;
//	printf("%lld",an);
	ans=((an-1)/2)%p;
	printf("%lld",ans%p);
	return 0;
}
