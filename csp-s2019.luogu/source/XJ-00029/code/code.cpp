#include<stdio.h>
int a[5000002][70];
int ch(long long int x,long long int y)
{
	long long int t,ans=1;
	for(t=0;t<y;t++)
	{
		ans=ans*x;
	}
	return ans;
}
int main()
{
	freopen("code.in","r",stdin);
	freopen("code.out","w",stdout);
	long long int i,j,n,k,p,g;
	scanf("%lld%lld",&n,&k);
	a[1][1]=0;
	a[2][1]=1;
	for(i=2;i<=n;i++)
	{
		p=ch(2,i);
		for(j=1;j<=p/2;j++)
		{
			for(g=i-1;g>=1;g--)
			{
				a[j][g+1]=a[j][g];
			}
			a[j][1]=0;
		}
		for(j=p/2+1;j<=p;j++)
		{
			for(g=1;g<=i;g++)
			{
				a[j][g]=a[p-j+1][g];
			}
			a[j][1]=1;
		}
	}
	for(i=1;i<=n;i++)
	{
		printf("%d",a[k+1][i]);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
