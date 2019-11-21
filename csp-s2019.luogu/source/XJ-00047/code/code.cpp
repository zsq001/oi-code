#include<stdio.h>
using namespace std;

long long d[70];
	
int main()
{
	int n;
	long long k;
	freopen("code.in","r",stdin);
	freopen("code.out","w",stdout);
	scanf("%d%lld",&n,&k);
	d[1]=2;k++;
	for(int i=2;i<=n;i++)
		d[i]=d[i-1]*2;
	while(n>1)
	{
		n--;
		if(k<=d[n])printf("0");
		else if(k>d[n])printf("1"),k=d[n+1]+1-k;
	}
	printf("%lld\n",k-1);
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}

