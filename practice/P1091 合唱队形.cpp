#include<iostream>
#define mmm 1001
using namespace std;
int n,a[mmm],dp[mmm][2],ans;
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	a[0]=0;
	for(int i=1;i<=n;i++)
	for(int j=0;j<i;j++)
	{
		if(a[i]>a[j])
		dp[i][0]=max(dp[i][0],dp[j][0]+1);
	} 
	a[n+1]=0;
	for(int i=n;i;i--)
	for(int j=n+1;j>i;j--)
	if(a[i]>a[j])
	dp[i][1]=max(dp[i][1],dp[j][1]+1);
	for(int i=1;i<=n;i++)
	ans=max(ans,dp[i][0]+dp[i][1]-1);
	cout<<n-ans;
	return 0;
}
