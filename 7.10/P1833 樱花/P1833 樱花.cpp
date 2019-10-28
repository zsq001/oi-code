#include<iostream>
#include<cstring>
#define mmax 100010
using namespace std;
int num[mmax],t[mmax],dp[mmax],mei[mmax];
int main()
{
	int h1,h2,m1,m2,n;
	char c1,c2;
	cin>>h1>>c1>>m1>>h2>>c2>>m2>>n;
	int time=(h2-h1)*60+m2-m1;
	for(int i=1;i<=n;i++)
	{
		cin>>t[i]>>mei[i]>>num[i];
		if(num[i]==0)
		num[i]=time/t[i];//最大时间 
	}
	for(int i=1;i<=n;i++)
		for(int j=1;num[i];j*=2)//二进制枚举 
		{
			if(num[i]<j) j=num[i];
			num[i]-=j;
			for(int k=time;k>=t[i]*j;k--)
			{
				dp[k]=max(dp[k],dp[k-t[i]*j]+mei[i]*j);
			}
		}
	cout<<dp[time];
	return 0;
}
