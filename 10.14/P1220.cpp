#include<iostream>
#include<cstdio>
#include<cstring>
#define mmm 1000
using namespace std;
int dp[2][mmm][mmm],a[mmm],b[mmm],tot[mmm];//0-l>r  1-l<r
int main()
{
	int n,c;
	cin>>n>>c;
	memset(dp,100,sizeof(dp));
	for(int i=1;i<=n;i++)
	{
		cin>>a[i]>>b[i];
		tot[i]=tot[i-1]+b[i];
	}
	dp[1][c][c]=dp[0][c][c]=0;
	for(int k=2;k<=n;k++)
	{
		for(int i=1;i+k-1<=n;i++)
		{
			int j=i+k-1;
			dp[0][i][j]=min(dp[0][i+1][j]+(a[i+1]-a[i])*(tot[i]+tot[n]-tot[j]),dp[1][i+1][j]+(a[j]-a[i])*(tot[i]+tot[n]-tot[j]));
			dp[1][i][j]=min(dp[1][i][j-1]+(a[j]-a[j-1])*(tot[n]-(tot[j-1]-tot[i-1])),dp[0][i][j-1]+(a[j]-a[i])*(tot[n]-(tot[j-1]-tot[i-1])));
		}
	}
	int ans=min(dp[1][1][n],dp[0][1][n]);
	cout<<ans<<endl;
	return 0;
}
