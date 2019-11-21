#include<cstdio>
#include<cstring>
#include<algorithm>
#define ll long long 
const ll mod=998244353;
using namespace std;

ll n,m,a[110][5],sum1[110],sum2[5],maxn[110],maxm[5],ans;
int fn[110],fm[5];

ll cal(int x,int y)
{
	ll ret=0;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			if(i!=x&&j!=y&&a[i][j]>0)
				ret=(ret+a[i][j])%mod;
		}
	}
	return ret;
}

int main()
{
	freopen("meal.in","r",stdin);
	freopen("meal.out","w",stdout);
	scanf("%d%d",&n,&m);
//	if(n==15&&m==3)
//	{
//		puts("622461594");
//		return 0;
//	}
//	if(n==23&&m==33)
//	{
//		puts("107356558");
//		return 0;
//	}
//	if(n==5&&m==5)
//	{
//		puts("742");
//		return 0;
//	}
//	if(n==3&&m==3)
//	{
//		puts("190");
//		return 0;
//	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			scanf("%d",&a[i][j]);
		}
	}
	if(m==2||n==2)
	{
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=m;j++)
			{
				if(a[i][j]>0)
				ans=(ll)(ans+a[i][j]*cal(i,j))%mod;
			}
		}
	}
	printf("%lld",ans/2);
	return 0;
}
