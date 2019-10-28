#include<iostream>
#define mmm 1001
using namespace std;
struct node{
	int ti,val;
}a[mmm];
int dp[mmm];
int main()
{
	int t,m;
	cin>>t>>m;
	for(int i=1;i<=m;i++)
	{
		cin>>a[i].ti>>a[i].val;
	}
	for(int i=1;i<=m;i++)
	{
		for(int j=t;j>=0;j--)
		{
			if(a[i].ti<=j)
			dp[j]=max(dp[j],dp[j-a[i].ti]+a[i].val);
		}
	}
	cout<<dp[t];
	return 0;
}
