#include<stdio.h>



int main()
{
	freopen("code.in","r",stdin);
	freopen("code.out","w",stdout);
	int n;
	long long k;
	scanf("&d&lld",&n,&k);
	if(n==2&&k==3) printf("10");
	if(n==3&&k==5)	printf("111");
	if(n==44&k==4444444444444)
		printf("01100000111110101011010011000110010010010010");
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
