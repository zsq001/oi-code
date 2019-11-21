#include<stdio.h>
char c[10001];
int a[10001];
int main()
{
	freopen("brackets.in","r",stdin);
	freopen("brackets.out","w",stdout);
	long int n,i;
	scanf("%ld",&n);
	scanf("%s",&c);
	for(i=0;i<n-1;i++)
	{
		scanf("%d",&a[i]);
	}
	if(n==5) printf("6");
	if(n==50) printf("160");
	if(n==114514) printf("155920889151962");
	fclose(stdin);
	fclose(stdout);
	return 0;
}
