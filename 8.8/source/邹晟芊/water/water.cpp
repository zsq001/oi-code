#include<iostream>
#include<cstdio>
#define mmm 10000010
typedef int int_;
#define int long long
const int mod=100000007;
using namespace std;
int a[mmm]={0,1};
int gcd(int a,int b)
{
	if(a==0) return b;
	return gcd(b%a,a);
}
int_ main()
{
	freopen("water.in","r",stdin);
	freopen("water.out","w",stdout);
	int n;
	cin>>n;
	for(int i=2;i<=n;i++)
	{
		a[i]=((a[i-1]/gcd(a[i-1],i))*i)%mod;
	}
	cout<<a[n]%mod;
	return 0;
}
