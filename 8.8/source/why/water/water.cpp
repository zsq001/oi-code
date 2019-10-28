#include<cstdio>
#include<cstring>
#include<algorithm>
#define maxn 50000050
using namespace std;
const int mo=1e9+7;
int n;
int t[maxn];
int f[maxn];
int a[11]={0,1,2,6,12,60,60,420,840,2520,2520};
bool ss(int k)
{
	for(int i=2;i*i<=k;i++)
	{
		if(k%i==0)
		{
			return false;
		}
	}
	return true;
}
int main()
{
	freopen("water.in","r",stdin);
	freopen("water.out","w",stdout);
	scanf("%lld",&n);
	int m=n;
	for(int i=1;i<=10;i++)
	{
		t[i]=a[i];
	}
	if(n<=10)
	{
		printf("%d",a[n]);
		return 0;
	}
	for(int i=11;i<=n;i++)
	{
		if(ss(i))
		{
			t[i]=i*t[i-1];
			t[i]%=mo;
		}
		else if(t[i-1]%i!=0)
		{
			for(int j=2;j;j++)
			{
				if(((j*t[i-1])%mo)%i==0)
				{
					t[i]=t[i-1]*j;
					t[i]%=mo;
					break;
				}
			}
		}
		else if(t[i-1]%i==0)
		{
			t[i]=t[i-1];
		}
	}
	printf("%d",t[n]%mo);
}

