#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#define mmm 110001
using namespace std;
struct node{
	int x,y,z;
}a[mmm];
int main()
{
	freopen("minecraft.in","r",stdin);
	freopen("minecraft.out","w",stdout);
	int b,n,d,m,ans=0;
	cin>>b>>n>>d>>m;
	for(int i=1;i<=n;i++)
	{	
		cin>>a[i].x;
		a[i].y=a[i].z=0;
		if(b==2||b==3)
			cin>>a[i].y;
		if(b==3)
			cin>>a[i].z;
	}
	for(int i=1;i<n;i++)
		for(int j=i+1;j<=n;j++)
		{
			if(abs(a[i].x-a[j].x)+abs(a[i].y-a[j].y)+abs(a[i].z-a[j].z)<=d)
				ans++;
		}
	cout<<ans;
	return 0;
}
