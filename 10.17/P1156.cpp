#include<iostream>
#include<cstdio>
#include<algorithm>
#define mmm 1000
using namespace std;
struct node{
	int t,f,h;
}a[mmm];
int dp[mmm];
bool cmp(node a,node b)
{
	return a.t<b.t;
}
int main()
{
	int d,g;
	cin>>d>>g;
	for(int i=1;i<=g;i++)
		cin>>a[i].t>>a[i].f>>a[i].h;
	sort(a+1,a+1+g,cmp);
	dp[0]=10;
	for(int i=1;i<=g;i++)
		for(int j=d;j>=0;j--)
		{
			if(dp[j]>=a[i].t)
			{
				if(a[i].h+j>=d)
				{
					cout<<a[i].t;
					return 0;
				}
				dp[j+a[i].h]=max(dp[j+a[i].h],dp[j]);
				dp[j]+=a[i].f;
			}
		}
	cout<<dp[0]<<endl;
	return 0;
}
