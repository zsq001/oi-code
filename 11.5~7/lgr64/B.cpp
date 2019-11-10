#include<iostream>
#include<cstdio>
using namespace std;
int now=-1,ans=0;
int main()
{
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		int x;
		cin>>x;
		if(x!=now)
		{
			ans++;
			now=x;
		}
	}
	cout<<ans<<endl;
	return 0;
}
