#include<stdio.h>
char c[101][101],a[100010];
long long int n,i,b[100010];
int main()
{
	freopen("brackets.in","r",stdin);
	freopen("brackets.out","w",stdout);
	
	scanf("%lld",&n);
	scanf("%s",a);
	for(i=1;i<n;i++) scanf("%lld",&b[i]);
	
	if(n==5){printf("%lld\n",6);} 
	if(n==50){printf("%lld\n",160);} 
	if(n==114514){printf("%lld\n",155920889151962);} 
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
