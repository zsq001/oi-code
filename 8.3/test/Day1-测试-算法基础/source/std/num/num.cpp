#include <cstdio>
#include <cstdlib>
#include <algorithm>

#define MAXX 1000000000000000000

typedef long long ll;

ll n,m,k;

ll f(ll x)
{
    ll i,ans=0;
    for(i=1;i<=n;i++)
       ans+=std::min(m,x/i);
    
    return ans;
}

void half()
{
    ll l=0,r=MAXX,mid,i;

    while(l != r)
    {
        mid=(l+r)/2;
        if(f(mid) < k) l=mid+1;
        else r=mid;
    }
    
    printf("%lld\n",l);
}

int main(void)
{
    freopen("num.in","r",stdin);
    freopen("num.out","w",stdout);
    
    scanf("%lld%lld%lld",&n,&m,&k);
    half();
    
    return 0;
}