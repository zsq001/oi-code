#include<iostream>
using namespace std;
int aa[100],av[100],bb[100],bv[100],cc[100],cv[100],dp[100000];
int main()
{
	freopen("budget.in","r",stdin);
	freopen("budget.out","w",stdout);
	int v,p,q,n,m,zhu=0,ans=-1;
	cin>>n>>m;
	for(int i=1;i<=m;i++)
	{
		cin>>v>>p>>q;
		//p*=v;
		if(q==0)
		{
			aa[i]=v;
			av[i]=p;
		}
		else 
		{
			if(bb[q]==0)
			{
				bb[q]=v;
			    bv[q]=p;
			}
			else{
				cc[q]=v;
				cv[q]=p;
			}
		}
	}
	for(int i=1;i<=m;i++)
	{
		for(int j=n;j>=aa[i];j--)
		{
			if(j-aa[i]>=0)
			dp[j]=max(dp[j],dp[j-aa[i]]+aa[i]*av[i]);
			if(j-bb[i]-aa[i]>=0)
			dp[j]=max(dp[j],dp[j-bb[i]-aa[i]]+aa[i]*av[i]+bb[i]*bv[i]);
			if(j-cc[i]-aa[i]>=0)
			dp[j]=max(dp[j],dp[j-cc[i]-aa[i]]+aa[i]*av[i]+cc[i]*cv[i]);
			if(j-bb[i]-aa[i]-cc[i]>=0)
			dp[j]=max(dp[j],dp[j-bb[i]-aa[i]-cc[i]]+aa[i]*av[i]+bb[i]*bv[i]+cc[i]*cv[i]);
			
		}
	}
	for(int i=1;i<=n;i++)
	{
		ans=max(ans,dp[i]);
	}
	cout<<ans;
	return 0;
}
