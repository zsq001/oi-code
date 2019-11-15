#include<stdio.h>
#define N 1000000007
long long f[4];
int n;
int main()
{
	freopen("coordinate.in","r",stdin);
	freopen("coordinate.out","w",stdout);
	scanf("%d",&n);
	f[1]=1;
	f[2]=1;
	for(int i=1;i<=n;i++)
	{
		f[3]=(2*f[2]+f[1])%N;
		f[1]=f[2];
		f[2]=f[3];		
	}
	printf("%I64d\n",f[3]);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
