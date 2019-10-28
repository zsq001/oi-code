#include<stdio.h>
int main()
{
	long long n;
	freopen("tree.in","r",stdin);
	freopen("tree.out","w",stdout);
	scanf("%lld",&n);
	n=n/2+1;
	printf("%lld",n);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
