#include<iostream>
#include<cstdio>
using namespace std;
struct node{
	int type,aa;
}a[100100];
double dp[100100];
int main()
{
	freopen("coal.in","r",stdin);
	freopen("coal.out","w",stdout);
	int n;
	double k,c,w;
	cin>>n>>k>>c>>w;
	for(int i=1;i<=n;i++)
		cin>>a[i].type>>a[i].aa;
	for(int i=n;i>=1;i--)
	{
		if(a[i].type==1)
			dp[i]=max(dp[i+1],dp[i+1]*(1-k*0.01)+a[i].aa);
		else
			dp[i]=max(dp[i+1],dp[i+1]*(1+c*0.01)-a[i].aa);
	}
	printf("%.2lf",dp[1]*w);
	return 0;
}
