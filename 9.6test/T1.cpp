#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
int a[1010];
using namespace std;
int main()
{
	freopen("a1.in","r",stdin);
	int t,n;
	cin>>t;
	for(int i=1;i<=t;i++)
	{
		int a1=0,a2=0,ans=0;
		cin>>n;
		memset(a,-1,sizeof(a));
		for(int i=1;i<=n;i++)
		{
			int x;
			cin>>x;
			a[i]=x%3;
			if(a[i]==0)
			ans++;
			if(a[i]==1)
			a1++;
			else if(a[i]==2)
			a2++;
		}
		while(a1>0&&a2>0)
		{
			ans++;
			a1--;
			a2--;
		}
		while(a1>1)
		{
			ans++;
			a1-=2;
		}
		while(a2>2)
		{
			ans++;
			a2-=3;
		}
		cout<<ans<<endl;
	}
	return 0;
}
