#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
#define mmm 110000
struct node{
	int a,t;
}a[mmm];
using namespace std;
bool cmp(node a,node b)
{
	return a.a*a.t>b.a*b.t;
}
int main()
{
	freopen("physics.in","r",stdin);
	freopen("physics.out","w",stdout);
	int n;
	cin>>n;
	double va=0,xa=0;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i].a>>a[i].t;
		xa+=va*a[i].t+0.5*a[i].a*pow(a[i].t,2);
		va+=a[i].a*a[i].t;
	}
	sort(a+1,a+1+n,cmp);	
	double vb=0,xb=0;
	for(int i=1;i<=n;i++)
	{
		xb+=vb*a[i].t+0.5*a[i].a*pow(a[i].t,2);
		vb+=a[i].a*a[i].t;
	}
	printf("%.1lf",xb-xa);
	return 0;
}
