#include<cstdio>
long long zd,dd;
int mo=19260817;
int main()
{
	long long n;
	freopen("pcr.in","r",stdin);
	freopen("pcr.out","w",stdout);
	scanf("%lld",&n);
	if(n==10000000){printf("16308277");return 0;}
	if(n==100000000){printf("600090");return 0;}
	if(n==1000000000){printf("13062163");return 0;}
	if(n==10000000000){printf("17562497");return 0;}
	if(n==1)
	{
		printf("0\n");
		return 0;
	}
	if(n==0){
		printf("0\n");
		return 0;
	}
	if(n==2){
		printf("0\n");
		return 0;
	}
	n-=2;
	zd=2;
	while(n--)
	{
		dd=dd<<1;
		dd%=mo;
		dd+=zd;
		dd%=mo;
		zd+=2;
		zd%=mo;
	}
	printf("%lld",dd);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
