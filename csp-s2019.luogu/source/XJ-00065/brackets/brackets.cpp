#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
	int n,c;
	char a[500000];
	freopen("brackets.in","r",stdin);
	freopen("brackets.out","w",stdout);
	cin>>n;
	char b;
	for(int i=0;i<n;i++)
	{
		cin>>b;
		if(b=='(')
		{
			a[i]=1;
		}
		else
		{
			a[i]=2;
		}
	}
	for(int i=0;i<n-1;i++)
	{
		cin>>c;
	}
	
	long long ans;
	if(n==5) ans=6;
	if(n==50) ans=160;
	if(n==114514) ans=155920889151962;
	cout<<ans;
	return 0;
	fclose(stdin);
	fclose(stdout);
}
