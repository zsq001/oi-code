#include<iostream>
#define mmm 1008611
int a[mmm],sum=0,l=-1,r,mid,m,n,tot,t;
using namespace std;
bool ju(int x,int a[])
{
	for(int i=0;i<n;i++)
	{
		if(tot+a[i]<=x)
		tot+=a[i];
		else
		tot=a[i],t++;
	}
	return t>=m;
}
int main()
{
	cin>>n>>m;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
		r+=a[i];
		l=l>a[i]?l:a[i];
	}
	while(l<=r)
	{
		tot=0,t=0;
		mid=(l+r)>>1;
		if(ju(mid,a))
		l=mid+1;
		else
		r=mid-1;
	}
	cout<<l;
	return 0;
}
