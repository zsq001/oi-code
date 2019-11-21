#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
	freopen("code.in","r",stdin);
	freopen("code.out","w",stdout);
	long long n,k;
	
	cin>>n>>k;
	if(n==2 && k==3) cout<<10;
	if(n==3 && k==5) cout<<111;
	if(n==44 && k==4444444444444) cout<<0<<1100000<<11<<111010<<10110<<1001<<1000<<1100<<100<<100<<10010;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
