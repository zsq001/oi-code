#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
const int mo=19260817;
long long n,k;
long long jn,jk,jm;
long long mod(long long u,long long v)
{
	return ((u%v)+v)%v;
}
void jc()
{
	jn=1;
	for(long long i=2;i<=n;i++)
	{
		jn*=i;
		jn%=mo;
	}
	jk=jn;
	for(long long i=n+1;i<=k;i++)
	{
		jk*=i;
		jk%=mo;
	}
	jm=jk;
	for(long long i=k+1;i<=3*n;i++)
	{
		jm*=i;
		jm%=mo;
	}
	
}
long long zhs1()
{
	return jk/((jn*jn)%mo);
}
long long zhs2()
{
	return jm/((jk*jn)%mo);
}
int main()
{
	freopen("blcup.in","r",stdin);
	freopen("blcup.out","w",stdout);
	scanf("%lld",&n);
	k=2*n;
	jc();
	printf("%lld",mod(6*(zhs2()-zhs1()),mo));
}
