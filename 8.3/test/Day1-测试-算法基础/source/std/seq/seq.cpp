#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
using namespace std;

#define MAX 23333333333333333

long double s[200005];
long double a[200005];
int n;

long double get(long double x)
{
    int i;
    for(i=1;i<=n;i++) a[i]=s[i]-x;
    long double ma=0,mi=0,ansmax=a[1],ansmin=a[1];

    for(i=1;i<=n;i++)
    {
        // printf("%Lf ma=%Lf mi=%Lf\n",a[i],ma,mi);
        ma=max(ma+a[i],a[i]);
        ansmax=max(ansmax,ma);
        mi=min(mi+a[i],a[i]);
        ansmin=min(ansmin,mi);
    }
    // puts("");

    ma=max(fabsl(ansmin),fabsl(ansmax));

    // printf("%Lf\n",ma);
    return ma;
}

void inp()
{
    int i;
    scanf("%d",&n);
    for(i=1;i<=n;i++)
        scanf("%Lf",&s[i]);
}

void three()
{
    long double l=-MAX,r=MAX,mid,mmid,i;

    while(r-l > 0.0000000000001)
    {
        // printf("[%Lf,%Lf]\n",l,r);
        mid=(l+r)/2;
        mmid=(mid+r)/2;

        if(get(mid)<get(mmid)) r=mmid;
        else l=mid;
    }

    printf("%.15Lf\n",get(l));
}

int main(void)
{
    freopen("seq.in","r",stdin);
    freopen("seq.out","w",stdout);
    
    inp();

    three();
    
    return 0;
}