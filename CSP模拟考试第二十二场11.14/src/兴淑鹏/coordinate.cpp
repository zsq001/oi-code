#include<stdio.h>
#include<string.h>
const long long mod=1e9+7;
struct X
{
	long long f[2][2];
	X() {memset(f,0,sizeof(f));};
};
X xc(X a,X b)
{
	X re;
	for(int i=0;i<2;i++)
		for(int j=0;j<2;j++)
		{
			for(int k=0;k<2;k++)
				re.f[i][j]+=a.f[i][k]*b.f[k][j];
			if(re.f[i][j]>=mod) re.f[i][j]%=mod;
		}
	return re;
}
int main()
{
	freopen("coordinate.in","r",stdin);
	freopen("coordinate.out","w",stdout);
	long long n;
	while(scanf("%I64d",&n)!=EOF)
	{
		X a;
		if(n==1) 
		{
			printf("3");
			continue;
		}
		else if(n==2)
		{
			printf("7");
			continue;
		}
		n-=3;
		a.f[0][1]=a.f[1][0]=1;
		a.f[1][1]=2;
		for(X b=a;n>0;n>>=1,b=xc(b,b))
			if(n&1) a=xc(a,b);
		printf("%I64d\n",(a.f[1][1]*7+a.f[1][0]*3)%mod);
	}
	return 0;
}
