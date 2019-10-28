#include<iostream>
#define mmm 10000
int a[mmm],dp[mmm];
using namespace std;
int main()
{
	int n,ans=0;
	cin>>n;
	for(int i=1;i<=n;i++)
	cin>>a[i];
	for(int i=1;i<=n;i++)
	{
		dp[i]=1;
	for(int j=1;j<i;j++)
	{
		if(a[i]<=a[j])
		dp[i]=max(dp[i],dp[j]+1);
	}
	ans=max(ans,dp[i]);
	}
	cout<<ans;
	return 0;
} 
