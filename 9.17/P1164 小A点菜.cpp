#include<iostream>
#include<cstdio>
using namespace std;
int a[2000],dp[110][10001];
int main(void)
{
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	cin>>a[i];
	for(int i=1;i<=n;i++)
	for(int j=1;j<=m;j++)
	{
		if(a[i]==j)
		dp[i][j]=dp[i-1][j]+1;
		else if(a[i]<j)
		dp[i][j]=dp[i-1][j-a[i]]+dp[i-1][j];
		else if(a[i]>j)
		dp[i][j]=dp[i-1][j];
	}
	cout<<dp[n][m];
	return 0;
}
