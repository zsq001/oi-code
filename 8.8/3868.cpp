#include <cstdio>
#include <algorithm>
using namespace std;

typedef long long ll;

#define x tmp.first
#define y tmp.second
#define pr pair<ll,ll>

ll Mod(ll a,ll p)		// a \in Z
{
	return (a%p+p)%p;
}

pr exgcd(ll a,ll b)
{
	if(b==0) return pr(1,0);
	pr tmp=exgcd(b,a%b);
	return pr(y,x-a/b*y);
}

ll getInv(ll a,ll p)     // get the inverse of a (mod p)
{
	pr tmp=exgcd(a,p);
	return Mod(x,p);
}

ll n,a[15],b[15];

void inp()
{
	scanf("%lld",&n);
	for(ll i=1;i<=n;i++)
		scanf("%lld",&a[i]);
	for(ll i=1;i<=n;i++)
		scanf("%lld",&b[i]);
	for(ll i=1;i<=n;i++)
		a[i]=Mod(a[i],b[i]);
}

ll times(ll X,ll b,ll mod)
{
	if(b==0) return 0;
	if(b==1) return X%mod;
	
	ll a=times(X,b/2,mod);
	
	if(b%2==0) return (a+a)%mod;
	return ((a+a)%mod+X)%mod;
}

void calc()
{
	ll C[15],m=1,M[15],ans=0;
	
	for(ll i=1;i<=n;i++)
		m*=b[i];
	for(ll i=1;i<=n;i++)
		M[i]=m/b[i];
	
	for(ll i=1;i<=n;i++)
		C[i]=times(M[i]*getInv(M[i],b[i])%m,a[i],m);
	for(ll i=1;i<=n;i++)
		ans = (ans+C[i])%m;
	printf("%lld\n",Mod(ans,m));
}

int main(void)
{
	inp();
	calc();
	
	return 0;
}
