#include<stdio.h>
#include<string.h>
#include<algorithm>
#define ll long long
using namespace std;
const int mod=1000000007;
int n;
ll f[505][50005],ans;
//void dfs(int last,int sum)
//{
//	if(sum==n)
//	{
//		anss=(anss+1)%mod;
//		return;
//	}
//	if(sum+last+1>n) return;
//	for(int i=last+1;i<=n&&sum+i<=n;++i) dfs(i,sum+i);
//}
int main()
{
//	freopen("b.in","r",stdin);
//	freopen("b.out","w",stdout);
	scanf("%d",&n);
//	dfs(0,0);
	int len=0,sum=0;
	while(sum<=n) sum+=++len;
	f[0][0]=1;
	for(int i=1;i<len;++i)
	{
		for(int j=(i*(i-1))>>1;j<=n;++j)
			f[i][j]=(f[i][j-i]+f[i-1][j-i])%mod;
		ans=(ans+f[i][n])%mod;
	}
	printf("%lld\n",ans);
//	printf("%lld\n",anss);
	return 0;
}
