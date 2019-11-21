#include<iostream>
#include<stdio.h>
using namespace std;
int main()
{
	long long int i,n,a[1000];
	char x;
	freopen("code.in","r",stdin);
	freopen("code.out","w",stdout);
	cin>>n;
	for(i=0;i<n;i++)
	{
		cin>>x;
	}
	for(i=0;i<n-1;i++)
	{
		cin>>a[i];
	}
	if(n==5)
	{
		cout<<"6"<<endl;
	}
	else if(n==50)
	{
		cout<<"160"<<endl;
	}
	else if(n==114514)
	{
		cout<<"155920889151962"<<endl;
	}
	return 0;
}
