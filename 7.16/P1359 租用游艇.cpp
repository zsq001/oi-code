#include<iostream>
#define mmm 1001
int a[mmm][mmm],dp[mmm];
using namespace std;
int main()
{
	int n,inf=21478888;
	cin>>n;
	for(int i=1;i<=n;i++)
	for(int j=i+1;j<=n;j++)
	{
		cin>>a[i][j]; 
		if(dp[j]==0)
		dp[j]=dp[j]+a[i][j];
		else 
		dp[j]=min(dp[j],dp[i]+a[i][j]);
	}
	cout<<dp[n];
	return 0;
}
