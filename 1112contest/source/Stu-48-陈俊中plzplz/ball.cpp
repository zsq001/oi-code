#include<cstdio>
#include<cstring>
#include<cmath> 
#include<algorithm>
#define ll long long 
const ll maxn=1e18;
using namespace std;

int n;
ll ans,a[55];
char ba[55];

int main()
{
	freopen("ball.in","r",stdin);
	freopen("ball.out","w",stdout);
	scanf("%d\n",&n);
	scanf("%s",ba+1);
	a[0]=1;
	for(int i=1;i<=51;i++) 
	{
		a[i]=a[i-1]<<1;
	}
	for(int i=1;i<=n;i++)
	{
		if(ba[i]=='B')
		{
			ans+=a[i-1];
			if(ans>maxn) 
			{
				puts("-1");
				return 0;
			}
		}
	}
	printf("%lld\n",ans);
	return 0;
}
