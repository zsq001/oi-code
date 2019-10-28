#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#define ll long long
using namespace std;
const int mod=19260817;
int N;
ll ksm(ll base,int tm)
{
	ll ans=1;
	while(tm){
		if(tm&1) ans=ans*base%mod;
		tm>>=1;
		base=(base*base)%mod;
	}
	return ans;
}
ll C(int n,int m)
{
	ll t1=1,t2=1;
	for(int i=1;i<=m;++i){
		t1=t1*i%mod;
		t2=t2*(n-i+1)%mod;
	}
	return t2*ksm(t1,mod-2)%mod;
}
int main()
{
	freopen("blcup.in","r",stdin);
	freopen("blcup.out","w",stdout);
	cin>>N;
	cout<<(C(N*3,N)-C(N*2,N)+mod)*6%mod<<endl;
	return 0;
}
