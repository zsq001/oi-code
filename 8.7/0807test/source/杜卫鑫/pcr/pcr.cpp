#include <stdio.h>
#include <string.h>
const long long mod =19260817;
long long ans[10][10],chu[10][10],res[10][10];
void chen1()
{
	long long c[10][10];
	for(int i=1;i<=3;i++)
		for(int j=1;j<=3;j++)
			c[i][j]=res[i][j];
	memset(res,0,sizeof(res));
	for(int i=1;i<=3;i++)
		for(int j=1;j<=3;j++)
			for(int k=1;k<=3;k++)
				res[i][j]=((c[i][k]*ans[k][j])%mod+res[i][j])%mod;
}
void chen2()
{
	long long c[10][10];
	for(int i=1;i<=3;i++)
		for(int j=1;j<=3;j++)
			c[i][j]=ans[i][j];
	memset(ans,0,sizeof(ans));
	for(int i=1;i<=3;i++)
		for(int j=1;j<=3;j++)
			for(int k=1;k<=3;k++)
				ans[i][j]=((c[i][k]*c[k][j])%mod+ans[i][j])%mod;
}
void POW(long long x)
{
	while (x)
	{
		if(x&1)chen1();
		x>>=1;
		chen2();
	}	
}
		
int main()
{
	long long n;
	freopen("pcr.in","r",stdin);
	freopen("pcr.out","w",stdout);
	scanf("%lld",&n);
	if(n==1||n==2)
	{
		printf("0\n");
		return 0;
	}
	ans[1][1]=1;ans[2][1]=1;ans[2][2]=1;ans[3][2]=1;ans[3][3]=2;
	chu[1][1]=2;chu[2][1]=2;
	res[1][1]=1;res[3][3]=2;res[2][1]=1;res[3][2]=1;res[2][2]=1;
	POW(n-3);
	for(int i=1;i<=3;i++)
		for(int j=1;j<=3;j++)
			ans[i][j]=0;
	for(int i=1;i<=3;i++)
		for(int j=1;j<=3;j++)
			for(int k=1;k<=3;k++)
				ans[i][j]=((res[i][k]*chu[k][j])%mod+ans[i][j])%mod;
	printf("%lld",ans[3][1]);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
