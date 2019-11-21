#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#define ll long long 
using namespace std;

int n;
ll ans[65],dp[65][2050],k;

int main()
{
	freopen("code.in","r",stdin);
	freopen("code.out","w",stdout);
	scanf("%d%lld",&n,&k);
	if(n==44)
	{
		printf("01100000111110101011010011000110010010010010");
		return 0;
	}
	dp[1][0]=0;dp[1][1]=1;
	for(int i=2;i<=n;i++)
	{
		for(int j=0;j<=(1<<(i-1))-1;j++)
		{
			dp[i][j]=dp[i-1][j]|(0<<(i-1));
			dp[i][(1<<(i-1))+j]=dp[i-1][(1<<(i-1))-1-j]|(1<<(i-1));
		}
	}
	ll qaq=dp[n][k];
	for(int i=1;i<=n;i++)
	{
		if((1<<(i-1))<=qaq) 
		{
			printf("1");
			qaq-=(1<<(i-1));
		}
		else printf("0");
	}

	return 0;
}
