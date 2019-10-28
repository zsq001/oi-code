#include<iostream>
#include<cstdio>
using namespace std;
int gcd(int a,int b)
{
	if(a==0) return b;
	return gcd(b%a,a);
}
int main()
{
	freopen("toad.in","r",stdin);
	freopen("toad.out","w",stdout);
	int x,y,m,n,l,poa,pob,ans=0;
	cin>>x>>y>>m>>n>>l;
	m%=l;
	n%=l;
	poa=x,pob=y;
	if(m==n)
	{
		cout<<"Impossible";
		return 0;
	}
	while(poa!=pob)
	{
		poa+=m;
		pob+=n;
		poa%=l;
		pob%=l;
		ans++;
	}
	cout<<ans;
}
