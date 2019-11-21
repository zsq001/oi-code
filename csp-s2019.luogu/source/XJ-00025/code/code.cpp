#include<iostream>
#include<stdio.h>
using namespace std;
int main()
{
	long long int i,n,k,s1=0,s=1;
	freopen("code.in","r",stdin);
	freopen("code.out","w",stdout);
	cin>>n>>k;
	for(int j=0;j<n;j++)
	{
		s*=2;
		s1=s/2;
	}
	long long fa[s];
	for(int j=0;j<s;i++)
	{
		fa[i]=i;
	}
	for(i=s-1;i>=s;i--)
	{
		fa[i]=fa[i];
	}
	cout<<fa[k]<<endl;	
	return 0;
}
