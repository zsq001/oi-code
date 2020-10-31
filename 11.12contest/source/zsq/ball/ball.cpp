#include<iostream>
#include<cstdio>
using namespace std;
char w[100];
typedef int int_;
#define int long long
int pow(int x,int y)
{
	int ww=1;
	for(int i=1;i<=y;i++)
	{
		ww*=x;
	}
	return ww;
}
int_ main()
{
	freopen("ball.in","r",stdin);
	freopen("ball.out","w",stdout);
	int n,ans=0;
	cin>>n;
	cin>>w+1;
	for(int i=1;i<=n;i++)
	{
		if(w[i]=='B')
		ans+=pow(2,i-1);
		if(ans>1e18)
		{
			cout<<"-1"<<endl;
			return 0;
		}
	}
	cout<<ans<<endl;
	return 0;
}
