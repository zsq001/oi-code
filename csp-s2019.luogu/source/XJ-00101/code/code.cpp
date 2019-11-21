#include<stdio.h>
unsigned long long a[70]={1};
void work(int n,unsigned long long k)
{
	if(n==0) return;
	if(k>=a[n-1])
	{
		printf("1");
		work(n-1,a[n]-k-1);
	}
	else
	{
		printf("0");
		work(n-1,k);
	}
}
int main()
{
	freopen("code.in","r",stdin);
	freopen("code.out","w",stdout);
	int n,i,j;
	unsigned long long k;
	scanf("%d%llu",&n,&k);
	for(i=1;i<=64;i++)
	{
		a[i]=a[i-1]*2;
	}
	work(n,k);
	return 0;
}
