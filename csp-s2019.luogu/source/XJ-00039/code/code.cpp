#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <iostream>
#include <math.h>
using namespace std;
int fastpow(long long int a,long long int b)
{
	long long int ans=1;
	while(b)
	{
		if(b&1) ans=ans*a;
		b=b/2;
		a=a*a;
	}
	return ans;
}
int main()
{
	long long int c,k; 
	int n;
	freopen("code.in","r",stdin);
	freopen("code.out","w",stdout);
	scanf("%d%lld",&n,&k);
	c=fastpow(2,n);
	while(n)
	{
		if(k+1>(c/2)) 
		{
			printf("1");
			k=c-k-1;
			c=c/2;
		}
		else
		{
			printf("0");
			c=c/2;
		}
		n--;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
