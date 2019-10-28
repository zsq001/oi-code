#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;
typedef int int_;
#define int long double
#define pow1 pow
int a[400100];
/*int pow1(int a,int b)
{
	for(int i=1;i<=b;i++)
		a*=a;
	return a;
}*/
bool cmp(int x,int y)
{
	return x>y;
}
int_ main()
{
	int_ n;
	cin>>n;
	for(int_ i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+1+n,cmp);
	int sa,ans=0;
	for(int_ i=1;i<n;i++)
	{
		if((int)(pow1(a[i],2)/i)<(int)(pow1(a[i]+a[i+1],2)/(i+1)))
		{
			ans=pow1(a[i]+a[i+1],2)/(i+1);
			a[i+1]+=a[i];
		}
		else
		{
			ans=pow1(a[i],2)/i;
			break;
		}
	}
	printf("%.8Lf",ans);
	return 0;
}
