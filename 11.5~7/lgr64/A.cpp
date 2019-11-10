#include<iostream>
#include<cstdio>
#define mmm 1010100
using namespace std;
typedef int int_;
#define int long long
int lll[mmm],a[mmm],sum[mmm];
int_ main()
{
	int n,k;
	cin>>n>>k;
	if(k>=n)
	{
		cout<<0<<endl;
		return 0;
	}
	for(int i=1;i<=n-1;i++)
	{
		cin>>a[i];
		if(i!=1)
			sum[i]=sum[i-1]+a[i];
		else
			sum[1]=a[i];
	}
	int maxl=-1,maxi;
	for(int i=1;i<=n-k;i++)
	{
		lll[i]=sum[i+k]-sum[i];
		if(lll[i]>maxl)
		{
			maxi=i;
			maxl=lll[i];
		}
	}
	cout<<sum[n-1]-lll[maxi]<<endl;
	return 0;
}
