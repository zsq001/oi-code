#include<iostream>
#include<cstdio>
#include<algorithm>
#define mmm 100000
typedef int int_;
#define int long long 
int_ a[mmm];
using namespace std;
int la=0,aa=0;
int gcd(int a,int b)
{
	return b?gcd(b,a%b):a;
}
int_ main()
{
	int_ n;
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1,a+1+n);
	for(int i=2;i<=n;i++)
	{
		la+=(i-1)*(a[i]-a[i-1]);
		aa+=la;
	}
	aa*=2;
	for(int i=1;i<=n;i++)
		aa+=a[i];
	int bb=n;
	int gy=gcd(aa,bb);
	aa/=gy;
	bb/=gy;
	cout<<aa<<" "<<bb;
	return 0;
}
