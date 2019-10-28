#include <cstdio>
#include <cstdlib>

#define MOD 19260817

typedef long long ll;

ll po(ll x,ll p)
{
    if(p==0) return 1;
    if(p==1) return x%MOD;

    ll a=po(x,p/2);

    if(p%2==0) return a*a%MOD;
    return a*a%MOD*x%MOD;
}

int main(void)
{
    freopen("pcr.in","r",stdin);
    freopen("pcr.out","w",stdout);
    
    ll n;
    scanf("%lld",&n);

    printf("%lld\n",((po(2,n)-2*n)%MOD+MOD)%MOD);

    return 0;
}
