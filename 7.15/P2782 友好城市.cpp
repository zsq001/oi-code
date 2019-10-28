#include<iostream>
#include<algorithm>
#define mmm 100000
using namespace std;
struct node{
	int x,y;
}a[300001];
int dp[mmm];
bool ju(node x,node y)
{
	return x.x<y.x;
}
int main()
{
	int n,ans=0;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i].x>>a[i].y;
	}
	sort(a+1,a+1+n,ju);
	for(int i=1;i<=n;i++)
	{
		dp[i]=1;
		for(int j=1;j<i;j++)
	{
		if(a[i].y>=a[j].y)
		dp[i]=max(dp[i],dp[j]+1);
	}
	ans=max(ans,dp[i]);
	}
	cout<<ans;
}
