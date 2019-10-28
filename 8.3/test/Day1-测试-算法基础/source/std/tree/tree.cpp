#include <cstdio>
#include <cstdlib>
#include <algorithm>
using namespace std;

typedef long long ll;

ll f(ll x)
{
    if(x==1) return 1;
    return 1+f(x/2);
}

int main(void)
{
    freopen("tree.in","r",stdin);
    freopen("tree.out","w",stdout);
    
    ll x;

    scanf("%lld",&x);
    printf("%lld\n",f(x));
    
    return 0;
}