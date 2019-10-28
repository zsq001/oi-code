#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;
const long long mod=1e8;
int a,b,c,d;
long long f[105][105][2][15][15],ans;
int main()
{
	freopen("homework.in","r",stdin);
	freopen("homework.out","w",stdout);
	scanf("%d%d%d%d",&a,&b,&c,&d);
	f[0][0][0][0][0]=f[0][0][1][0][0]=1;
	for(int day=1;day<=a+b;++day)
	{
		for(int k=0;k<=day&&k<=a;++k)
		{
			int g=day-k;
			if(g>b) continue;
			if(k)
			{
				for(int j=1;j<=d;++j)
					f[k][g][0][1][0]=(f[k-1][g][1][0][j]+f[k][g][0][1][0])%mod;
				for(int i=1;i<=c;++i)
					f[k][g][0][i][0]=(f[k-1][g][0][i-1][0]+f[k][g][0][i][0])%mod;
			}
			if(g)
			{
				for(int i=1;i<=c;++i)
					f[k][g][1][0][1]=(f[k][g-1][0][i][0]+f[k][g][1][0][1])%mod;
				for(int j=1;j<=d;++j)
					f[k][g][1][0][j]=(f[k][g-1][1][0][j-1]+f[k][g][1][0][j])%mod;
			}
		}
	}
	for(int i=1;i<=c;++i)
		ans=(ans+f[a][b][0][i][0])%mod;
	for(int j=1;j<=d;++j)
		ans=(ans+f[a][b][1][0][j])%mod;
	printf("%lld",ans);
	return 0;
}
