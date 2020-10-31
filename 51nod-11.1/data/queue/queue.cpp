#include<stdio.h>
#define MAX  50001
int a[MAX];
int main()
{
	int n,max=0,m;
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&m);
		a[m]=a[m-1]+1;
		if(a[m]>max)
			max = a[m];
	}
	printf("%d",n-max);
}