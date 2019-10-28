#include<iostream>
#include<cstdio>

#define mmm 5000
const int inf=2147483647;
int n,dp1[mmm][mmm],dp2[mmm][mmm],a[mmm],sum[mmm],ma=-1,mi=0; 
using namespace std;
int main()
{
	cin>>n;
	for(int i=1;i<=2*n;i++)
	{
		cin>>a[i];
		a[i+n]=a[i];
		sum[i]=sum[i-1]+a[i];
	}
	for(int w=1;w<n;w++)
	{
		for(int i=1,j=i+w;(j<2*n)&&(i<2*n);i++,j=i+w)
		{
			dp2[i][j]=inf;
			for(int k=i;k<j;k++)
			{
				dp1[i][j]=max(dp1[i][j],dp1[i][k]+dp1[k+1][j]+sum[j]-sum[i-1]);
				dp2[i][j]=min(dp2[i][j],dp2[i][k]+dp2[k+1][j]+sum[j]-sum[i-1]);
			}
		}
	}
	mi=inf;
	for(int i=1;i<=n;i++)
	{
		ma=max(ma,dp1[i][i+n-1]);
		mi=min(mi,dp2[i][i+n-1]);
		
	}
	cout<<mi<<endl<<ma;
	return 0;
}
