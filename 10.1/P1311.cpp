#include<iostream>
#include<cstdio>
using namespace std;
#define mmm 100000
int pi,num[mmm],co[mmm];
int main()
{
	int n,be,k,p,now,ans=0;
	cin>>n>>k>>p;
	for(int i=1;i<=n;i++)
	{
		cin>>co[i]>>pi;
		if(pi<=p)
		{
			for(int j=i;j>be;j--)
				num[co[j]]++;
			be=i;
			ans+=num[co[i]]-1;
		}
		else
			ans+=num[co[i]];
	}
	cout<<ans;
	return 0;
}
