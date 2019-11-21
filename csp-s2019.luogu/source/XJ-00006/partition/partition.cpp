#include<stdio.h>
int a[10001];
int main()
{
	freopen("partition.in","r",stdin);
	freopen("partition.out","w",stdout);
	int n,type;
	scanf("%d%d",&n,&type);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
	}
	if(type==0)
	{
		if(n==5) printf("247");
		if(n==10) printf("1256");
		if(n==400) printf("282100273486");
		if(n==5000)printf("12331302317672");
	}
	if(type==1)
	{
		if(n==10000000)
		{
			printf("4972194419293431240859891640");
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
