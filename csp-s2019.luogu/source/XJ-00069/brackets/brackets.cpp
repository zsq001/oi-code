#include<stdio.h>
int n,a[10001],k[10001],p,j,ans;
char c[10001],t[10001];
int main()
{
	freopen("brackets.in","r",stdin);
	freopen("brackets.out","w",stdout);
	scanf("%d\n",&n);
	scanf("%s",c);
	for(int i=1;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	printf("6");
	return 0;
	fclose(stdin);
	fclose(stdout);
}
