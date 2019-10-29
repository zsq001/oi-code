#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;
const int mod=1e9+7;
template<class T>void read(T &x)
{
	bool f=0;x=0;char s=getchar();
	while(s>'9'||s<'0'){f|=(s=='-');s=getchar();}
	while(s>='0'&&s<='9'){x=(x<<1)+(x<<3)+(s^48);s=getchar();}
	x=f?-x:x;
}
int T,n,k,a[1005],f[10005];
void solve1()
{
	int i,j;
	memset(f,0,sizeof(f));
	for(i=1;i<=n;++i)
	{
		read(a[i]);
		if(a[i]<=k) f[a[i]]++;
	}
	sort(a+1,a+n+1);
	f[1]=((1ll*f[1]*(f[1]-1))/2)%mod;
	for(i=1;i<=n;++i)
	{
		if(a[i]==a[i-1]) continue;
		for(j=1;j<=k&&(1ll*a[i]*j<=k);++j)
		{
			if(a[i]==j) f[j*j]=(1ll*f[j*j]+1ll*f[j]*(f[j]-1)/2)%mod;
			else f[j*a[i]]=(1ll*f[j*a[i]]+1ll*f[j]*f[a[i]])%mod;
		}
	}
	printf("%d\n",f[k]%mod);
}
int main()
{
	freopen("banana.in","r",stdin);
	freopen("banana.out","w",stdout);
	read(T);
	while(T--)
	{
		read(n),read(k);
		if(k<=10000) solve1();
	}
	return 0;
}
