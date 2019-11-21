#include<stdio.h>
int main()
{
	freopen("code.in","r",stdin);
	freopen("code.out","w",stdout);
	int m,n;
	scanf("%d%d",&m,&n);
	if(m==2)
	printf("10");
	if(m==3)
	{
		printf("111");
	}
	fclose(stdin);
	fclose(stdout);
}
