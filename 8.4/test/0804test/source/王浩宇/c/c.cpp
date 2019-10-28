#include<cstdio>
#include<cstring>
#include<algorithm>
#define maxn 1000050
typedef int int_;
#define int long long
using namespace std;
int n,m,a[maxn],ans;
void dfs(int l)
{
	int now=1,nextx,nextn,maxx=0,minn=0,f=0;
	while(now!=n)
	{
		for(int p=1;p<=l;p++)
		{
			if(now+p==n)
			{
				if(a[n]>=a[now])
				{
					ans++;
					return;
				}
				else return;
			}
			if(a[now+p]>=a[now]&&a[now+p]>maxx)
			{
				maxx=a[now+p];
				nextx=now+p;
			}
			else if(a[now+p]>=a[now]&&a[now+p]<=maxx)
			{
				if(now+p>nextx)nextx=now+p;
			}
			if(a[now+p]<a[now]&&a[now+p]>minn)
			{
				minn=now+p;
				f=1;
			}
		}
		if(f==0)
		{
			now=nextx;
			ans++;
		}
		else now=minn;
		f=0;minn=0;maxx=0;
	}
}
int_ main()
{
	int k;
	freopen("c.in","r",stdin);
	freopen("c.out","w",stdout);
	scanf("%lld",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",&a[i]);
	}
	scanf("%lld",&m);
	for(int i=1;i<=m;i++)
	{
		ans=0;
		scanf("%lld",&k);
		dfs(k);
		printf("%lld\n",ans);
	}
}
