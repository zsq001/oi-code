#include<iostream>
#include<cstdio>
#include<algorithm>
#include<queue>
#define mmm 20001
using namespace std;
typedef int int_;
#define int long long 
int a[mmm];
int_ main()
{
	freopen("box.in","r",stdin);
	freopen("box.out","w",stdout);
	int t,ans;
	cin>>t;
	for(int i=1;i<=t;i++)
	{
		int n,ansa=0,k1=0,ansb=0,k2=0;
		cin>>n;
		for(int j=1;j<=n;j++)
		{
			cin>>a[j];
			if(j%2==1)
			{
				ansa+=a[j];
				k1=1;
			}
			else 
			{
				ansb+=a[j];
				k2=1;
			}
		}
		if(k1==k2&&k1==0)
		cout<<"0"<<endl;
		else if(k2==0)
		cout<<ansa<<endl;
		else
		{
			if(ansa>=ansb)
			{
				ans=ansa-ansb;
				cout<<ans<<endl;
			}
			else
			{
				ans=ansb-ansa;
				cout<<ans<<endl;
			}
		}
	}
	return 0;
}
