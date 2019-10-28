#include<iostream>
using namespace std;
long long dp[400][400];
int main()
{
	int n,m,x1,x2,y1,y2;
	cin>>n>>m;
	cin>>x1>>y1>>x2>>y2;
	dp[x1][y1]=1;
	for(int i=x1+1;i<=x2;i++)
	for(int j=1;j<=n;j++)
	dp[i][j]=dp[i-2][j-1]+dp[i-2][j+1]+dp[i-1][j-2]+dp[i-1][j+2];
	cout<<dp[x2][y2];
	return 0;
} 
