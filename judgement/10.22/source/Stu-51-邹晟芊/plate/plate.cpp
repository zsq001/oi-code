#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;
int a[500][100000];
int abs1(int x)
{
	if(x<0)
	return -x;
	else 
	return x;
}
int main()
{
	freopen("plate.in","r",stdin);
	freopen("plate.out","w",stdout);
	int n,m,p,cnt=0,ans=0;
	cin>>n>>m>>p;
	for(int i=1;i<=n;i++)
	{
		int s1,s2,cnt=0;
		cin>>s1>>s2;
		a[i][++cnt]=abs1(s2-s1);
		for(int j=3;j<=m;j++)
		{
			int x,y;
			cin>>x;
			a[i][++cnt]=abs1(x-s2);
			s2=x;
		}
		sort(a[i],a[i]+cnt);
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=i;j<=n;j++)
		{
			if(i==j)
			continue;
			int y=0;
			for(int w=1;w<=n;w++)
			{
			if(a[i][w]!=a[j][w])
			{
				y=1;
				break;
			}
		}
			if(y==0)
			ans++;
		}
	}
	cout<<ans<<endl;
	return 0;
}
