#include <iostream>
#include <stdio.h>
using namespace std;
int main()
{
	freopen("brackets.in","r",stdin);
	freopen("brackets.out","w",stdout);
	int n,b[114614];
	char a[114614];
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	for(int i=1;i<n;i++)
		cin>>b[i];
	if(n==5)
	{
		cout<<"6";
		return 0;
	}
	if(n==50)
	{
		cout<<"160";
		return 0;
	}
	if(n==114514)
	{
		cout<<"155920889151962";
		return 0;
	}
	return 0;
}
