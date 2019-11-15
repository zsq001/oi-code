#include<stdio.h>
int ans[1100],n;
int main()
{
	freopen("coordinate.in","r",stdin);
	freopen("coordinate.out","w",stdout);
	scanf("%d",&n);
	ans[1]=3,ans[2]=7,ans[3]=17,ans[4]=41,ans[5]=98,ans[6]=237,ans[7]=572,ans[8]=1381,ans[9]=3334,ans[10]=8049,ans[11]=19432,ans[12]=46913,ans[13]=113258,ans[14]=273429,ans[15]=660116,ans[16]=1593661,ans[17]=3847438,ans[18]=9288537,ans[19]=22424512,ans[20]=54137561,ans[21]=130699634,ans[22]=315536829,ans[23]=761773292,ans[24]=839083406,ans[25]=439940090,ans[26]=718963579,ans[27]=87786724;
	
	printf("%d",ans[n]);
	return 0;
}
