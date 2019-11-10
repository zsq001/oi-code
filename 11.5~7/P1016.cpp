#include<iostream>
#include<cstdio>
#include<stack>
typedef int int_;
#define int double
#define mmm 1000000
using namespace std;
int d[mmm],p[mmm],sum[mmm];
int_ sta[mmm],ne[mmm];
int_ main()
{
//	reopen("wayhome.in","r",stdin);
//	freopen("wayhome.out","w",stdout);
	int n,t;
	cin>>n>>t;
	for(int_ i=1;i<=n;i++)
	{
		cin>>sum[i]>>p[i];
		if(d[i]>t)
		{
			cout<<"No Solution"<<endl;
			return 0;
		}
	}
	int_ qwq=0;
	for(int_ i=n;i;i--)
	{
		while(qwq and p[sta[qwq]]>p[i])
			qwq--;
		ne[i]=sta[qwq];
		sta[++qwq]=i;
		if(!ne[i])
			ne[i]=n+1;
	}
	int ans=0;
	int now=0,dis=0;
	for(int_ i=1;i<=n;i++)
	{
		now-=d[i-1];
		dis=min(sum[ne[i]-1]-sum[i-1],t);
		if(now<dis)
		{
			ans+=(dis-now)*p[i];
			now=dis;
		}
	}
	cout<<ans<<endl;
	return 0;
}
