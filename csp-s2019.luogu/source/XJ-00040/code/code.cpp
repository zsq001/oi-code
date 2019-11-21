#include <stdio.h>
#include <math.h>
int main()
{
	int n,l,s,p,q;
	long long k;
	freopen("code.in","r",stdin);
	freopen("code.out","w",stdout);
	scanf("%d %lld",&n,&k);
	l = n - 1;
	for(int i = 1 ; i <= n ; i++)
	{
		s = pow(2,l);
		l--;
		p = k / s;
		q = k % s;
		while(p >= 4) p -= 4;
		if(p == 0) 		printf("0");
		else if(p == 1) printf("1");
		else if(p == 2) printf("1");
		else if(p == 3) printf("0");
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
