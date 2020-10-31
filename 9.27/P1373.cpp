#include<iostream>
#include<cstdio>
const int mod=1000000007;
int a[801][801],dp[801][801][17][2];//0 a 1u
using namespace std;
int main()
{
	//freopen("4.in","r",stdin);
	int n,m,k,ans=0;
	cin>>n>>m>>k;
	k++;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
		{	 
			cin>>a[i][j];
			dp[i][j][a[i][j]%k][0]=1;
		}
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			for(int w=0;w<=k;w++)
			{
				dp[i][j][w][0]=(dp[i][j][w][0]+dp[i-1][j][(w-a[i][j]+k)%k][1])%mod;
				dp[i][j][w][0]=(dp[i][j][w][0]+dp[i][j-1][(w-a[i][j]+k)%k][1])%mod;
				dp[i][j][w][1]=(dp[i][j][w][1]+dp[i-1][j][(w+a[i][j])%k][0])%mod;
				dp[i][j][w][1]=(dp[i][j][w][1]+dp[i][j-1][(w+a[i][j])%k][0])%mod;
			}
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			ans=(ans+dp[i][j][0][1])%mod;
	cout<<ans<<endl;
	return 0;
}
