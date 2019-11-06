#include<iostream>
#include<algorithm>
using namespace std;
#define mmm 100100
int w[mmm],val[mmm],blg[mmm],att[mmm][3],dp[mmm];
int main()
{
	int W,n;
	cin>>W>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>w[i]>>val[i]>>blg[i];
		val[i]*=w[i];
		if(blg[i]!=0)
		{
			if(att[blg[i]][1]==0)
			att[blg[i]][1]=i;
			else
			att[blg[i]][2]=i;
		}
	}
	for(int i=1;i<=n;i++)
	{
		if(blg[i]!=0) 
		continue;
		for(int k=W;k>=0;k--)
		{
			if(k>=w[i]) dp[k]=max(dp[k],dp[k-w[i]]+val[i]);
			if(k>=w[i]+w[att[i][1]]) dp[k]=max(dp[k],dp[k-w[i]-w[att[i][1]]]+val[i]+val[att[i][1]]);
			if(k>=w[i]+w[att[i][2]]) dp[k]=max(dp[k],dp[k-w[i]-w[att[i][2]]]+val[i]+val[att[i][2]]);
			if(k>=w[i]+w[att[i][1]]+w[att[i][2]]) dp[k]=max(dp[k],dp[k-w[i]-w[att[i][1]]-w[att[i][2]]]+val[i]+val[att[i][1]]+val[att[i][2]]);
		}
	}
	cout<<dp[W];
	return 0;
}
