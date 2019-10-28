#include <cstdio>

typedef long long ll;

ll A,B,d;

ll gcd(ll a,ll b)
{
    if(b==0) return a;
    return gcd(b,a%b);
}

ll check(ll x,ll y)
{
    return x%d==0 && y%d==0;
}

void work()
{
    ll a,b,x,y,ans=1;
    scanf("%lld%lld%lld%lld",&a,&b,&x,&y);
    A=2*a;
    B=2*b;
    d = gcd(A,B);

    ans = check(x,y)+check(x+a,y+b)+check(x+b,y+a)+check(x+a+b,y+a+b);
    printf("%c\n",ans?'Y':'N');
}

int main(void)
{
    freopen("vector.in","r",stdin);
    freopen("vector.out","w",stdout);

    int T;
    scanf("%d",&T);

    while(T--)
        work();

    return 0;
}