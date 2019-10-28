#include<stdio.h>
int n;
int ans=0,b=2333333,mod=1000000007,z=1;
int work(int a)
{
	int p=a/2;
	return p;
}
int main()
{
	freopen("b.in","r",stdin);
	freopen("b.out","w",stdout);
	scanf("%d",&n);
	while(b>1)
	{
		n--;
		b=work(n);
		z--;
		b=b+z;
		ans+=b;
	}
	printf("%d",(ans+1)%mod);
	return 0;
}

