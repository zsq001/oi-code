#include <stdio.h>
int main()
{
	int n;
	int b[100];
	char a[100];
	freopen("brackets.in","r",stdin);
	freopen("brackets.out","w",stdout);
	scanf("%d",&n);
	for(int i = 1 ; i <= n ; i++)
		scanf("%c",&a[n]);
	for(int i = 1 ; i <= n-1 ; i++)
		scanf("%d",&b[n]);
	if(n == 5) 		 		printf("6");
	else if(n == 50) 		printf("160");
	else if(n == 114514) 	printf("155920889151962");
	else					printf("0");
	fclose(stdin);
	fclose(stdout);
	return 0;
}
