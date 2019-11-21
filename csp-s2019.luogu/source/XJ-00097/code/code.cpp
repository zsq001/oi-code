#include <iostream>
#include <stdio.h>
using namespace std;
int d[65],n,a=1,b=1,c[2]={0,1},j[2]={1,0};
unsigned long long k;
int main()
{
	freopen("code.in","r",stdin);
	freopen("code.out","w",stdout);
	ios::sync_with_stdio(false);
	cin>>n>>k;
	b=n*2+(n-2)*2;
	for(int i=1;i<=n;++i)
	{
		b/=2;
		if(k>=b/2)
		{
			if(k%2) cout<<j[(k/2)%2];
			else cout<<j[k/2%2];
		}
		else 
		{
			if(k%2) cout<<c[(k/2)%2];
			else cout<<c[k/2%2];
		}
		k/=2;
	}
    return 0;
}
