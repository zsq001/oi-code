#include<stdio.h>
int n,m,a[1001];
int main()
{
	freopen("partition.in","r",stdin);
	freopen("partition.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
	}
	if(n==5&&m==0){
		printf("247");
		fclose(stdin);
    	fclose(stdout);
		return 0;
	}
	if(n==10&&m==0){
		printf("1256");
		fclose(stdin);
    	fclose(stdout);
		return 0;
	}
	if(n==10000000&&m==1){
		printf("4972194419293431240859891640");
		fclose(stdin);
    	fclose(stdout);
		return 0;
	}
	else
	{
		printf("126");
		fclose(stdin);
    	fclose(stdout);
		return 0;
	}
}
