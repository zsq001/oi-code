#include<cstdio>
#include<iostream>
using namespace std;
int main()
{
	int n,ans=0,t;
	double a;
	cin>>a;
	for(int i=1;i<=n;i++)
	{
		cin>>a>>t;
		for(int j=1;j<=t;j++)
			ans^=(int)(j*a);
	}
	cout<<ans;
	return 0;
}
