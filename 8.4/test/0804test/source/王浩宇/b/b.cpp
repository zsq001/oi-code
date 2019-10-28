#include<cstdio>
#include<cstring>
#include<algorithm>
#define maxn 1000010
typedef int int_;
#define int long long
using namespace std;
int n,m,p,q,a[maxn],d[maxn];
void color(int now,int last)
{
	int l1=(now*p+q)%n+1,l2=(last*p+q)%n+1,r1=(now*q+p)%n+1,r2=(last*q+p)%n+1;
	if(l1>r1)swap(l1,r1);
	if(l2>r2)swap(r1,r2);
	for(int i=l1;i<=r1;i++)
	{
		if(i>=l2&&i<=r2) a[i]=0;
		a[i]=now;
	}
}
int_ main()
{
	freopen("b.in","r",stdin);
	freopen("b.out","w",stdout);
	scanf("%lld%lld%lld%lld",&n,&m,&p,&q);
	for(int i=1;i<=m;i++)
	{
		color(i,i-1);
	}
	for(int i=1;i<=n;i++)
	{
		printf("%lld\n",a[i]);
	}
}
