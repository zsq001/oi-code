#include <stdio.h>
long long cimi1(int x)
{
	long long base=1;
	for(int i=1;i<=x;i++)
		base=base*2;
	return base;
}	
int main()
{
	freopen("code.in","r",stdin);
	freopen("code.out","w",stdout);
	int n;
	long long k;
	scanf("%d %lld",&n,&k);	
	if(k<=(cimi1(63)-1))
	{
		long long mid;
		while(n)
		{
			mid=cimi1(n-1)-1;
			if(k>mid){printf("1");n--;k=mid+1-k+mid;}
			else     {printf("0");n--;}
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
