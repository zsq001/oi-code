#include<cstdio>
#include<algorithm>
#include<cstring>
typedef int int_;
#define int long long
using namespace std;
char a[60];
int n,f[60],ans;
int calc(int mi)
{
	int k=1;
	for(int i=1;i<=mi-1;i++)
	{
		k*=2;
	}
	return k;
}
int_ main()
{
	freopen("ball.in","r",stdin);
	freopen("ball.out","w",stdout);
	scanf("%lld",&n);
	for(int i=0;i<=n;i++)
	{
		scanf("%c",&a[i]);
		if(a[i]=='B')
		{
			f[i]=1;
			ans+=calc(i);
			if(ans>1e18)
			{
				printf("-1");
				return 0;
			}
		}
	}
	printf("%lld",ans);
}
