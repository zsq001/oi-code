#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int a[110000],b[10100];
bool cmp(int x,int y)
{
	return x>y;
}
int main()
{
//	freopen("road.in","r",stdin);
//	freopen("road.out","w",stdout);
	int ans=0,n,mmax=-1;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		b[a[i]]++;
		mmax=max(mmax,a[i]);
	}
//	sort(b+1,b+1+mmax,cmp);
	while(mmax!=0)
	{
		int k=0;
		for(int i=1;i<=n;i++)
		{
			if(k==0 and a[i]==0)
				continue;
			if(a[i]!=0)
				k=1;
			if(k==1 and a[i]==0)
				break;
			if(k==1)
			{
				a[i]--;
				b[a[i]]++;
				b[a[i]+1]--;
			}
		}
		mmax=0;
		for(int i=1;i<=n;i++)
			mmax=max(mmax,a[i]);
//		sort(b+1,b+1+mmax,cmp);
		ans++;
	}
	cout<<ans<<endl;
	return 0;
}
