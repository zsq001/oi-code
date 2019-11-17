#include<cstdio>
#include<algorithm>
typedef int int_;
#define int long long
using namespace std;
int n,m;
int a[200020];
int find(int l,int r)
{
	int maxx=0;
	int minn=1e9+7;
	for(int i=l;i<=r;i++)
	{
		if(a[i]>maxx)maxx=a[i];
		if(a[i]<minn)minn=a[i];
	}
	return maxx-minn;
}
void query(int l,int r,int x,int y)
{
	a[l]=x;
	for(int i=l+1;i<=r;i++)
	{
		a[i]=a[i-1]+y;
	}
}
int_ main()
{
	freopen("gem.in","r",stdin);
	freopen("gem.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	int f,x,y,l,r;
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",&a[i]);
	}
	while(m--)
	{
		scanf("%lld",&f);
		if(f==1)
		{
			scanf("%lld%lld",&l,&r);
			printf("%lld\n",find(l,r));
		}
		if(f==2)
		{
			scanf("%lld%lld%lld%lld",&l,&r,&x,&y);
			query(l,r,x,y);
		}
	}
}
