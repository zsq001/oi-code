#include<stdio.h>
long long int a[1000005];
long long int n,m,p,q;
long long int write(int x)
{
	if(x<0)
	{
		putchar('-');
		x=-x;
	}
	if(x>9)
	{
		write(x/10);
	}
	putchar(x%10+'0');
}
int main()
{
	freopen("b.in","r",stdin);
	freopen("b.out","w",stdout);
	long long int i,j;
	scanf("%lld%lld%lld%lld",&n,&m,&p,&q);
	for(i=1;i<=m;++i)
	{
		if(((i*p+q)%n+1)<=((i*q+p)%n+1))
		{
			for(j=(i*p+q)%n+1;j<=(i*q+p)%n+1;++j)
			{
				a[j]=i;
			}	
		}
		else if(((i*p+q)%n+1)>((i*q+p)%n+1))
		{
			for(j=(i*q+p)%n+1;j<=(i*p+q)%n+1;++j)
			{
				a[j]=i;
			}
		}
	}
	for(i=1;i<=n;++i)
	{
		write(a[i]);
		putchar('\n');
	}
	return 0;
}
