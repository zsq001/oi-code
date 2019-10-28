#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define mmm 30000
using namespace std;
int m,n,dp[mmm],a[100],pa[mmm],ans=0,anss=0,tot;
void dp1()
{
	memset(dp,0,sizeof(dp));
	dp[0]=1;
	ans=tot=0;
	for(int i=0;i<n;i++)
	{
		if(pa[i])
			continue;
		for(int j=tot;j>=0;j--)
			if(dp[j]&&!dp[j+a[i]])
				dp[j+a[i]]=1,ans++;
		tot+=a[i];
	}
	anss=max(anss,ans);
}
void dfs(int p,int f)
{
	if(f>m)
		return ;
	if(p==n)
	{
		if(f==m)
		dp1();
		return ;
	}
	dfs(p+1,f);
	pa[p]=1;
	dfs(p+1,f+1);
	pa[p]=0;
}
int main()
{
	cin>>n>>m;
	for(int i=0;i<n;i++)
		scanf("%d",&a[i]);
	dfs(0,0);
	cout<<anss;
	return 0;
}
