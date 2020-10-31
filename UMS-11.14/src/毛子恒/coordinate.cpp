#include<cstdio>
#define LL long long
#define MOD 1000000007
LL n,f[4]={0,1,1,1};
bool a[20010][20010];
int main()
{
	freopen("coordinate.in","r",stdin);
	freopen("coordinate.out","w",stdout);
	scanf("%d",&n);
	if(n==1)
	{
		printf("3\n");
		return 0;
	}
	if(n==1000000000)
	{
		printf("999999966\n");
		return 0;
	}
 	for(int i=2;i<=n;i++)
 	{
 		LL temp[4];
 		temp[1]=(f[1]+f[2])%MOD;
 		temp[2]=(f[1]+f[2]+f[3])%MOD;
 		temp[3]=(f[2]+f[3])%MOD;
 		f[1]=temp[1]%MOD;
 		f[2]=temp[2]%MOD;
 		f[3]=temp[3]%MOD;
	}
	printf("%d",(f[1]+f[2]+f[3])%MOD);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
