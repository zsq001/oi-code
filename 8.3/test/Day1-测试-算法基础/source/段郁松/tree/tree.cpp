#include<stdio.h>
long long int a,l,n;
int main()
{
	freopen("tree.in","r",stdin);
	freopen("tree.out","w",stdout);
	scanf("%lld",&a);
	n=a;
	while(n>0)
	{
		n=n/2;
		l++;
	}
	printf("%d",l);
	return 0;
}
