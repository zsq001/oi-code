#include<iostream>
using namespace std;
int v[31],dp[21000];
int main()
{
	int w,n;
	cin>>w>>n;
	for(int i=1;i<=n;i++)
	cin>>v[i];
	for(int i=1;i<=n;i++)
	for(int j=w;j>=v[i];j--)
	{
		if(dp[j]<dp[j-v[i]]+v[i])
		dp[j]=dp[j-v[i]]+v[i];
	}
	cout<<w-dp[w];
	return 0;
}

