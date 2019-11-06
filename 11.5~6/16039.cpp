#include<iostream>
#include<cstdio>
#include<stack>
typedef int int_;
#define int long long
#define mmm 1000000
using namespace std;
int d[mmm],p[mmm],sum[mmm],sta[mmm],ne[mmm];
int_ main()
{
	freopen("wayhome.in","r",stdin);
	freopen("wayhome.out","w",stdout);
	int n,t;
	cin>>n>>t;
	for(int i=1;i<=n;i++)
	{
		cin>>d[i]>>p[i];
		sum[i]=sum[i-1]+d[i];
		if(d[i]>t)
		{
			cout<<-1<<endl;
			return 0;
		}
	}
	int qwq=0;
	for(int i=n;i;i--)
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
	for(int i=1;i<=n;i++)
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
