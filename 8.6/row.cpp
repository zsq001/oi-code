#include <cstdio>
#include <cstdlib>
#include <map>
#include <cstring>
using namespace std;

typedef long long ll;

map <int,int> row;
ll n,a[100005],b[100005];

void input()
{
    ll i,x,y;
    scanf("%lld",&n);

    for(i=1;i<=n;i++)
    {
        scanf("%lld%lld",&x,&y);
        a[i]=x;
        b[i]=y;
        
        row[x]++;
    }
}

void calc()
{
    ll i;
    long long ans=0;
    for(i=1;i<=n;i++)
        ans+=row[b[i]];

    printf("%lld\n",ans);
}

void init()
{
    row.clear();
    memset(a,0,sizeof(a));
    memset(b,0,sizeof(b));
    
}

void work()
{
    init();
    input();
    calc();
}

int main(void)
{
    ll t;
    scanf("%lld",&t);

    while(t--) 
        work();
    
    return 0;
}
