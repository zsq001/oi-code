#include <cstdio>
#include <algorithm>
using namespace std;

typedef long long ll;
#define pr pair<ll,ll>
#define X tmp.first
#define Y tmp.second

ll gcd(ll a,ll b)
{
    if(b==0) return a;
    return gcd(b,a%b);
}

pr exgcd(ll a,ll b)
{
    if(b == 0) return pr(1,0);
    pr tmp = exgcd(b,a%b);
    return pr(Y,X-a/b*Y);
}

int main(void)
{
    freopen("toad.in","r",stdin);
    freopen("toad.out","w",stdout);

    ll x,y,m,n,L,P,Q,d,k,step;
    pr tmp;

    scanf("%lld%lld%lld%lld%lld",&x,&y,&m,&n,&L);
    P = m-n;
    Q = y-x;

    d=gcd(P,L);
    if(Q%d != 0) goto fuck;
    tmp=exgcd(P,L);

    k=X;

    k*=Q/d;
    step = abs(L/d);
    k=(k%step+step)%step;

    printf("%lld\n",k);
    return 0;

    fuck:
    puts("Impossible");

    return 0;
}