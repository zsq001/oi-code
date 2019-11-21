#include<stdio.h>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;
int main()
{
	freopen("code.in","r",stdin);
	freopen("code.out","w",stdout);
	int i,j,n,a[100],x=1;
	long long k,q=1;
	memset(a,0,sizeof(a));
	scanf("%d %lld",&n,&k);
	for(i=1;i<n;i++) q*=2;
	while(q>=1)
	{
		if(k>q-1)
		{
			a[x++]=1;
			k=q*2-k-1;
			q/=2;
		}
		else if(k<q)
		{
			a[x++]=0;
			k=k;
			q/=2;
		}
	}
	for(i=1;i<x;i++) printf("%d",a[i]);
	return 0;
}

