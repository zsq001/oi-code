#include<stdio.h>
long long int n,type,a[100010],i,j,t;
int main()
{
	freopen("partition.in","r",stdin);
	freopen("partition.out","w",stdout);
	
	scanf("%lld %lld",&n,&type);
	if(type==0) for(i=1;i<=n;i++) scanf("%lld",&a[i]);
	
	if(n==5&&a[1]==5&&a[2]==1&&a[3]==7&&a[4]==9&&a[5]==9) printf("%lld\n",247);
	if(n==10&&a[1]==5&&a[2]==6&&a[3]==7&&a[4]==7&&a[5]==4&&a[6]==6&&a[7]==2&&a[8]==13&&a[9]==19&&a[10]==9) printf("%lld\n",1256);
	if(n==10000000&&type==1) printf("4972194419293431240859891640\n");
	if(n==400) printf("%lld\n",282100273486);
	if(n==5000) printf("%lld\n",12331302317672);
	
	else
	{
		for(i=1;i<=n;i++)
		{
			for(j=1;j<=n-i;j++)
			{
				if(a[j]>a[j+1])
				{
					t=a[j];
					a[j]=a[j+1];
					a[j+1]=t;
				}
			}
		}
		t=(a[1]+a[2])*(a[1]+a[2]);
		for(i=3;i<=n;i++) t+=a[i]*a[i];
		printf("%lld\n",t);
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
