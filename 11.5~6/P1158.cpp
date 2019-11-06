#include<iostream>
#include<cstdio>
#include<algorithm>
#define mmm 101000
using namespace std;
struct node{
	int to1,to2;
}a[mmm];
bool cmp(node a,node b)
{
	return a.to1<b.to1;
}
int pow1(int a)
{
	return a*a;
}
int main()
{
	int x1,x2,y1,y2;
	cin>>x1>>y1>>x2>>y2;
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		int x,y;
		cin>>x>>y;
		a[i].to1=pow1(x-x1)+pow1(y-y1);
		a[i].to2=pow1(x-x2)+pow1(y-y2);
	}
	sort(a+1,a+1+n,cmp);
	int ans=a[n].to1;
	int qwq=-1;
	for(int i=n-1;i>=1;i--)
	{
		qwq=(qwq<a[i+1].to2)?a[i+1].to2:qwq;
		ans=min(ans,qwq+a[i].to1);
	}
	cout<<ans<<endl;
	return 0;
}
