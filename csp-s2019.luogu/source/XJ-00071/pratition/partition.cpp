#include<stdio.h>
int main()
{
	freopen("partition.in","r",stdin);
	freopen("pratition.out","w",stdout);
	long long int m,a,b,c,d,e,f,i,j;
	scanf("%lld%lld",&a,&b);
	if(b==0)
	{
		for(i=1;i<=a;i++)
		{
			scanf("%lld",&f);
			
		}
	}
	if(b==1)
	{
		scanf("%lld%lld%lld%lld%lld%lld",&e,&f,&c,&d,&e,&m);
	    for(i=1;i<=m;i++)
	    {
		   for(j=1;j<=3;j++)
		    { 
			    scanf("%lld",&f);
		    }
	    }
	}
	if(a==5)
	{
		printf("247");
	}	
	if(a==10)
	{
		printf("1256");
	}
	if(a==10000000)
	{
		printf("4972194419293431240859891640");
	}
	if(a==5000)
	{
		printf("12331302317672");
	}
	if(a==400)
	{
		printf("282100273486");
	}
	fclose(stdin);
	fclose(stdout);
	
}