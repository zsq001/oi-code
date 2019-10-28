#include<stdio.h>
#include<stdlib.h>
int n,m,k,t[33000000];
int main()
{
	freopen("num.in","r",stdin);
	freopen("num.out","w",stdout);
	long long i,j,k,sum=0;
	scanf("%d%d%lld",&n,&m,&k);
	if(n==1||m==1)
	{
		printf("%lld\n",k);
		return 0;
	}
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=m;j++)
		{
			if(i*j>=33000000||i*j>k)
			{
				break;
			}
			t[i*j]++;
		}
	}
	i=1;
	while(sum+t[i]<k)
	{
		sum+=t[i];
		i++;
	}
	printf("%lld",i);
	return 0;
}
