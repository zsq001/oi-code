#include <cstdio>
#include <bitset>
using namespace std;

#define MOD 100000007
typedef long long ll;

int p[10000005],tot,n;
bitset <100000005> f;

void getPrime(int n)
{
    int a,i;

    for(a=2;a<=n;a++)
    {
        if(f[a] == 0)
            p[++tot] = a;
        for(i=1;i<=tot && a*p[i]<=n;i++)
        {
            f[a*p[i]] = 1;
            if(a%p[i] == 0) break;
        }
    }
}

ll calc(int x)
{
    ll ans=x;
    while(ans <= n) ans*=x;
    return ans/x%MOD;
}

void work()
{
    int i;
    ll ans=1;
    for(i=1;i<=tot;i++)
        ans=(ans*calc(p[i]))%MOD;
    printf("%lld\n",ans);
}

int main(void)
{
    freopen("water.in","r",stdin);
    freopen("water.out","w",stdout);

    scanf("%d",&n);
    getPrime(n);

    work();

    return 0;
}