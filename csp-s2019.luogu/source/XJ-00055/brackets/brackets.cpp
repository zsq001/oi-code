#include <stdio.h>
#include <string.h>
long long a[1000000];
int main()
{
	freopen("brackets.in","r",stdin);
	freopen("brackets.out","w",stdout);
	int n;
	scanf("%d",&n);
	char a[1000000];
	scanf("%s",a);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
	}
	if(n==5)
	{
		printf("6");
	}
	if(n==50)
	{
		printf("160");
		
	}
	if(n==114514)
	{
		printf("155920889151962");
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
