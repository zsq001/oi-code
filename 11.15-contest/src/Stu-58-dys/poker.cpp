#include<stdio.h>
#include<string.h>
#include<math.h>
#include<algorithm>
#define ll long long int
using namespace std;
ll n,jo,a[100],ji;
ll l,r,mid;
bool cmp(ll a,ll b)
{
	return a<b;
}
ll work(ll p)
{
	ll j=1;
	ll ans=0;
	while(a[j]<p)
	{
		ans+=(p-a[j]);
		++j;
	}
	if(ans>jo) return 0;
	else return 1;
}
int main()
{
	ll i;
	scanf("%lld%lld",&n,&jo);
	ji+=jo;
	for(i=1;i<=n;++i)
	{
		scanf("%lld",&a[i]);
		ji+=a[i];
	}
	r=ji/3;
	sort(a,a+1+n,cmp);
	while(r-l>=5)
	{
		mid=(l+r)/2;
		if(work(mid)) l=mid+1;
		else r=mid;
	}
	for(i=r;i>=l;--i)
	{
		if(work(i)) 
		{
			printf("%lld",i);
			break;
		}
	}
	return 0;
}
