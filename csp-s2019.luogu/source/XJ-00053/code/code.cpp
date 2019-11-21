#include<stdio.h>
int main()
{
	int a[100];	
	int n,i;
	long long num=1,k;
	freopen("code.in","r",stdin);
	freopen("code.out","w",stdout);
	scanf("%d %lld",&n,&k);
	k=k+1;
	if(n==1)
	{
		if(k==2) printf("1");
		else     printf("0");
		return 0;
	}
	for(i=1;i<n;i++)
		num=num*2;
	for(i=1;i<=n;i++)
	{		
		if(k>num) 
		{
			a[i]=1;
			k=num-k+1;
			k=k+num;
		}
		else if(k<=num)
			a[i]=0;	
		num=num/2;
		if(num<=2)   num=2;
	}	
	for(i=1;i<n;i++)
		printf("%d",a[i]);
	if(k==2) printf("1");
	else     printf("0");
	fclose(stdin);
	fclose(stdout);
	return 0;
}
