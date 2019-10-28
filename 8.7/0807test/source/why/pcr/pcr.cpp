#include<cstdio>
#include<algorithm>
using namespace std;
typedef int int_;
#define int long long
int n,f=0,fou;
int ksm(int a,int b)
{
	int ans=1,d=a;
	while(b>0)
	{
		if(b&1)ans*=d;
		ans%=19260817;
		d*=d;
		d%=19260817;
		b>>=1;
	}
	return ans;
}
int_ main()
{
	freopen("pcr.in","r",stdin);
	freopen("pcr.out","w",stdout);
	scanf("%lld",&n);
	printf("%lld",abs((ksm(2,n)%19260817)-((2*n)%19260817)%19260817));
}
