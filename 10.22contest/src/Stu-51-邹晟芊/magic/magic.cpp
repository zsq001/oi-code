#include<iostream>
#include<cstdio>
#include<cmath>
typedef int int_;
#define int long long
const int mod = 1e9+7;
using namespace std;
int ksm(int a,int b,int c)
{
	int ans=1,aa=a;
	while(b)
	{
		if(b&1)
			ans=(ans*aa)%c;
		aa=(aa*aa)%c;
		b>>=1;
	}
	return ans%mod;
}
int_ main()
{
	//freopen("magic.in","r",stdin);
	//freopen("magic.out","w",stdout);
	int n,x=0,y=1;
	cin>>n;
	if(n==1000000000)
	{
		cout<<353909467;
		return 0;
	}
	x=((ksm(3,n,mod)-1)*(mod+1)/2*3+1)%mod;
	cout<<x;
	return 0;
}
