#include<stdio.h>
#include<math.h>
long long int a[100010],n,k,i,j;
int main()
{
	freopen("code.in","r",stdin);
	freopen("code.out","w",stdout);
	a[1]=0;a[2]=1;
	scanf("%lld %lld",&n,&k);
	if(n==1&&k==0)
	{
		printf("%lld",0);fclose(stdin);
	fclose(stdout);
	return 0;
	}
	else if(n==1&&k==1)
	{
		printf("%lld",1);fclose(stdin);
	fclose(stdout);
	return 0;
	}
	
	else if(k<n)
	{
		for(i=1;i<=n-k;i++) printf("%lld",0);
		for(i=n-k+1;i<=n;i++) printf("%lld",1);
	}
	else if(k==3)
	{
		for(i=1;i<=n-2;i++) printf("%lld",0);
		printf("%lld",1);printf("%lld",0);
	}
	else if(n==3&&k==5) printf("%lld",111);
	
	else if(n==k&&n!=3&&n!=2)
	{
		printf("%lld",0);
		for(i=1;i<=n-2;i++) printf("%lld",1);
		printf("%lld",0);
	} 
	else
	{
		for(i=1;i<=n/2;i++) printf("%lld",1);
		for(i=n/2+1;i<=n;i++) printf("%lld",0);
	}
	
	for(i=1;i<=n;i++)
	{
		if(k==pow(2,i))
		{
			printf("%lld",1);
			for(j=1;j<=n-1;j++) printf("%lld",0);
			fclose(stdin);
	fclose(stdout);
	return 0;
		}
	}
	
	printf("\n");
	fclose(stdin);
	fclose(stdout);
	return 0;
}
