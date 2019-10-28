#include<iostream>
typedef int int_;
#define int unsigned long long
using namespace std;
int_ main()
{
	freopen("tree.in","r",stdin);
	freopen("tree.out","w",stdout);
	int n,ans=0;
	cin>>n;
	if(n==1)
	{
		puts("1");
		return 0; 
	}
	if(n&1)
	{
		ans++;
		n--;
		n/=2;
		ans+=n;
	}
	else
	{
		ans++;
		n/=2;
		ans+=n;
	}
	cout<<ans;
	return 0;
} 
