#include<cstdio>
#include<algorithm>
using namespace std;
typedef int int_;
#define int long long
#define inf 2000000000000000000

int n;
char s[100];
int dp[100][2];

int_ main()
{
	freopen("ball.in","r",stdin);
	freopen("ball.out","w",stdout);
	scanf("%lld",&n);
	scanf("%s",s);
	if(s[0]=='R') dp[0][1]=0;
	else dp[0][1]=1;
	dp[0][0]=1;
	for(int i=1;i<n;i++){
		if(dp[i-1][0] > 5e17 || dp[i][0]<0) dp[i][0]=-inf;
		else dp[i][0]=2*dp[i-1][0]+1;
		if(s[i] == 'R') dp[i][1]=dp[i-1][1];
		else dp[i][1]=dp[i-1][1]+1+dp[i-1][0];
		if(dp[i][1] < 0 || dp[i][1] > 1e18){
			printf("-1");
			return 0;
		}
	}
	printf("%lld",dp[n-1][1]);
	return 0;
}
/*
100
BBRBRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRR

*/
