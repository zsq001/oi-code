#include<iostream>
#define mmm 50000
using namespace std;
struct node{
	int val,w;
}a[mmm];
int dp[mmm];
int main()
{
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=m;i++)
	{
		cin>>a[i].w>>a[i].val;
		a[i].val*=a[i].w;
	}
	for(int i=1;i<=m;i++)
	{
		for(int j=n;j>=a[i].w;j--)
		{
			if(a[i].w<=j)
			dp[j]=max(dp[j],dp[j-a[i].w]+a[i].val);
		}
	} 
	cout<<dp[n];
	return 0;
} 
