/*保证a数组长于b数组*/
#include<cstdio>
#include<algorithm>
#include<iostream>
using namespace std;
int n,m,x,y;
int a[101000],b[101000];
int j=1,ans=0;
int main()
{
	freopen("match.in","r",stdin);
	freopen("match.out","w",stdout);
	cin>>n>>m>>x>>y;
	if(n<m)
	{
		swap(x,y);
		for(int i=1;i<=n;i++)
			cin>>b[i];
		for(int i=1;i<=m;i++)
			cin>>a[i];
		for(int i=1;i<=n&&j<=m;i++)
		{
			while(b[i]>a[j]+y&&j<=m)
				j++;
			if(b[i]>=a[j]-x&&j<=m)ans++,j++;
		}
	}
	else 
	{
		for(int i=1;i<=n;i++)
			cin>>a[i];
		for(int i=1;i<=m;i++)
			cin>>b[i];
		for(int i=1;i<=m&&j<=n;i++)
		{
			while(b[i]>a[j]+y&&j<=n)
				j++;
			if(b[i]>=a[j]-x&&j<=n)ans++,j++;
		}
	}
	
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
} 
