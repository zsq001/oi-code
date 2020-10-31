#include<cstdio>
#include<algorithm>
typedef int int_;
#define int long long
using namespace std;
int a[1010],b[1010];
int n,m,x,y,ans;
int_ main()
{
	freopen("match.in","r",stdin);
	freopen("match.out","w",stdout);
	scanf("%lld%lld%lld%lld",&n,&m,&x,&y);
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",&a[i]);
	}
	for(int i=1;i<=m;i++)
	{
		scanf("%lld",&b[i]);
	}
	for(int i=1;i<=m;i++)
	{
		for(int j=1;j<=n;j++)
		{
			if(a[j]==0)
			{
				continue;
			}
			if(a[j]<=b[i]+x&&a[j]>=b[i]-y)
			{
				ans++;
				a[j]=0;
				break;
			}
		}
	}
	printf("%lld",ans);
}
