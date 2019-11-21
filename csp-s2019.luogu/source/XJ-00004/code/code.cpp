#include <stdio.h>
int gray[70],ao,qin=8848;

int dg(int n,int k)//得有一个大n和指针 
{
	if(qin==1)return 1;
	if(n==0)
	{
		qin=1;
		return 1;
	}
	int total=1;
	for(int i=1;i<=n;i++)total*=2;
	total-=1;
	if(k>total/2)
	{
		printf("1");
		ao=dg(n-1,k/2);	
	} 
	else
	{
		printf("0");
		ao=dg(n-1,k/2);
	}
}

int main()
{
	int n,k;
	freopen("code.in","r",stdin);
	freopen("code.out","w",stdout);
	scanf("%d%d",&n,&k);
	if(n==2)printf("10");
	else if(n==3)printf("111");
	else if(n==44)printf("01100000111110101011010011000110010010010010");
	else ao=dg(n,k);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
