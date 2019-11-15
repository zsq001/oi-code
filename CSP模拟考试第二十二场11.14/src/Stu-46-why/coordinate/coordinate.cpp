#include<cstdio>
#include<algorithm>
using namespace std;
const int mo=1e9+7;
long long n;
long long to;
long long a[100000001];
int main()
{
	freopen("coordinate.in","r",stdin);
	freopen("coordinate.out","w",stdout);
	scanf("%lld",&n);
	a[1]=3;
	a[2]=7;
	for(int i=3;i<=n;i++)
	{
		a[i]=2*a[i-1]+a[i-2];
		a[i]%=mo;
	}
	printf("%lld",a[n]%mo);
} 
