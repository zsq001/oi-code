#include<iostream>
#include<cstdio>
#define mmm 1000
using namespace std;
int a[mmm],b[mmm],dp[mmm][mmm];
int main()
{
	int n,m,t;
	cin>>n>>m>>t;
	for(int i=1;i<=n;i++)
		cin>>a[i]>>b[i];
	for(int i=1;i<=n;i++)
	{
		for(int j=m;j>=a[i];j--)
		for(int k=t;k>=b[i];k--)
		dp[j][k]=max(dp[j][k],dp[j-a[i]][k-b[i]]+1);
	}
	cout<<dp[m][t];
	return 0;
}
