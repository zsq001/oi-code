#include<cstdio>
#include<algorithm>
using namespace std;
long long a[60];
long long n,m;
long long ans;
int main()
{
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",&a[i]);
	}
	a[n+1]=m;
	sort(a+1,a+n+2);
	for(int i=1;i<=2;i++)
	{
		for(int j=n+1;j>=3;j--)
		{
			a[j]-=a[i];
		}
		ans+=a[i];
		a[i]-=a[i];
		sort(a+i,a+n+2);
	}
	printf("%lld",ans);
	return 0;
}
