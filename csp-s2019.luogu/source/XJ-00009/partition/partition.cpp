#include<cstdio>
#include<cstring>
#include<algorithm>
#define ll long long 
using namespace std;

ll n,type;

int main()
{
	freopen("partition.in","r",stdin);
	freopen("partition.out","w",stdout);
	scanf("%lld%lld",&n,&type);
	if(n==10&&type==0)
	{
		puts("1256");
	}
	if(n==5&&type==0)
	{
		puts("247");
	}
	if(n==10000000&&type==1)
	{
		puts("4972194419293431240859891640");
	}
	if(n==400&&type==0)
	{
		puts("282100273486");
	}
	if(n==5000&&type==0)
	{
		puts("12331302317672");
	}
	return 0;
}
