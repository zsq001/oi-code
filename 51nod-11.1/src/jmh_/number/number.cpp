#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
#define mod 1000000007


int dp[1000050];
int n,maxn,ans;



int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
    dp[0]=dp[1]=1;
    maxn=1;
	scanf("%d",&n);
    for(int i=2;i<=n;i++){
    	if( i/(1<<maxn) >=2) maxn+=1;
    	if(i%2!=0) dp[i]=dp[i-1];
    	int temp=(i-2)>>1;
    	
        if(dp[temp+1]==0) dp[i]=(dp[i-2]+dp[1<<maxn])%mod;
    	else dp[i]=(dp[i-2]+dp[temp+1])%mod;
	}
	printf("%d",dp[n]);
	return 0;
}
