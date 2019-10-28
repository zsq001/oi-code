#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
typedef int int_;
#define int long long
int aw[100000],vis[100000];/*
int gcd(int a,int b)
{
	return b?gcd(b,a%b):a;
}*/
int_ main()
{
//	freopen("money.in","r",stdin);
//	freopen("money.out","w",stdout);
	int t,a,b;
	cin>>t;
	while(t--)
	{
		memset(aw,0,sizeof(aw));
		memset(vis,0,sizeof(vis));
		int n,mmax=0,ans=0;
		cin>>n;
		int qwq=n;
		for(int i=1;i<=n;i++)
		{
			cin>>aw[i];
			mmax=max(mmax,aw[i]);
		}
		sort(aw+1,aw+1+n);
		for(int i=1;i<=n;i++)
		{
			if(vis[aw[i]])
				continue;
			vis[aw[i]]=1;
			ans++;
			for(int k=aw[i];k<=mmax;k++)
			{
				if(vis[k-aw[i]])
					vis[k]=1;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
