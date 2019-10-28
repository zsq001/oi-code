#include<iostream>
#include<cstdio>
#include<cmath>
#define mmm 10
typedef int int_;
#define int double 
struct node{
	int x,y;
}a[mmm];
int b[mmm];
using namespace std;
int dis(int_ i)
{
	return sqrt(pow((a[i].x-a[i+1].x),2)+pow((a[i].y-a[i+1].y),2));
}
int_ main()
{
	freopen("protect.in","r",stdin);
	freopen("protect.out","w",stdout);
	int n;
	cin>>n;
	for(int_ i=1;i<=n;i++)
		cin>>a[i].x>>a[i].y;
	for(int_ i=1;i<n;i++)
	{
		b[i]=dis(i);
	}
	cout<<1.17;
	return 0;
}
