#include<bits/stdc++.h>
using namespace std;
long long int m,n,u,c[100000],ans,f[100000],ji;


int main()
{
	freopen("centroid.in","r",stdin);
	freopen("centroid.out","w",stdout);
	scanf("%lld",&m);
	for(int i=0;i<m;i++)
	{
		scanf("%lld",&c[i]);
		for(int j=0;j<c[i]-1;j++)
		{
			scanf("%lld %lld",&n,&u);
			ans+=n;
			ans+=u;
		}
		f[ji]=ans+u*2;
		ans=0;
		ji++;
	}
	for(int i=0;i<ji;i++)
	{
		printf("%lld\n",f[i]);
	}
	return 0;
	
}
