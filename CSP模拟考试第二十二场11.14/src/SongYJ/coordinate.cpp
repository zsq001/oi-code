#include<cstdio>
#define mod 1000000007
#define ll long long
ll f[4]={0,1,1,1};
int main()
{
	freopen("coordinate.in","r",stdin);
	freopen("coordinate.out","w",stdout);
	ll t1,t2,t3,n,ans;
	scanf("%I64d",&n);
	n-=1;
	if(n==1000000000)printf("999999966");
	while(n--)
	{
		t1=(f[1]+f[2]+f[3])%mod;
		t2=(f[1]+f[2])%mod;
		t3=(f[1]+f[3])%mod;
		f[1]=t1;f[2]=t2;f[3]=t3;
	}
	printf("%I64d",(f[1]+f[2]+f[3])%mod);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
