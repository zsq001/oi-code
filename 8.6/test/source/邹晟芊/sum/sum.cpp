#include<iostream>
#include<cstdio>
#define mmm 200000
//typedef int int_;
const int mod=1000000007;
using namespace std;
int a[mmm],b[mmm]={0,1,1};
int main()
{
	freopen("sum.in","r",stdin);
	freopen("sum.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	cin>>a[i];//1 1 2 3 5 8 13 21 34 55'
	for(int i=3;i<=n;i++)
	b[i]=(b[i-1]+b[i-2])%(1000000007);
	for(int i=1;i<=m;i++)
	{
		int x,l,r,z;
		cin>>x;
		if(x==1)
		{
			cin>>l>>r>>z;
			for(int j=l;j<=r;j++)
			a[j]+=z;
		}
		if(x==2)
		{
			int lll=0;
			cin>>l>>r;
			for(int i=l;i<=r;i++)
			{
				lll=((lll%mod)+(b[a[i]]%mod))%mod;
			}
			cout<<lll<<endl;
		}
	}
	return 0;
}
