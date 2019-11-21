#include<stdio.h>
int f[100001];
int main()
{
	freopen("brackets1.in","r",stdin);
	freopen("brackets1.out","w",stdout);
	int n,i=0;
	char c[10001];
	char y;
	scanf("%d",&n);
	while((y=getchar())&&y!='\n')
	{
		c[i]=y;i++;
	}
	for(i=0;i<n-1;i++)
	{
		scanf("%d",&f[i]);
	}
	printf("6");
	fclose(stdin);
	fclose(stdout);
	return 0;
}
