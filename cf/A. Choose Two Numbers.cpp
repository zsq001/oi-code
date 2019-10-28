#include<iostream>
#include<cstdio>
#include<cstdlib>
#define mmm 1000
using namespace std;
int a[mmm],b[mmm];
int main(void)
{
	int n,m,maxa,maxb;
	cin>>n;
	for(int i=1,w;i<=n;i++)
	{
		cin>>w;
		a[w]=1;
	}
	cin>>m;
	for(int i=1,w;i<=m;i++)
	{
		cin>>w;
		b[w]=1;
	}
//	sort(a+1,a+1+n);
//	sort(b+1,b+1+m);
	for(int i=1;i<=n;i++)
	for(int j=1;j<=m;j++)
	{
		int k=1,c;
		if(a[i]!=0&&b[j]!=0)
		{
			c=i+j;
		}
		else continue;
		if(a[c]==1)
		{
			k=0;
		}
		if(b[c]==1)
		{
			k=0;
		}
		if(k==0)
		break;
		cout<<i<<" "<<j;
		exit(0);
	}
}
