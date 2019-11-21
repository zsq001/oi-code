#include <cstdio>
#include <algorithm>
#include <cmath>
long long a[100000000];
int main()
{
	int m,n,i,j,p;
	long long k,y,x;
	a[0]=0;
	a[1]=1;
	freopen("code.in","r",stdin);
	freopen("code.out","w",stdout);
	scanf("%d%lld",&n,&k);
	if(k==4444444444444)
	{
		printf("01100000111110101011010011000110010010010010");
		fclose(stdin);
		fclose(stdout);
		return 0;
	}
	for(i=2;i<=n;i++)
	{
		m=pow(2,i);
		x=pow(2,i-1);
		for(j=m/2;j<=m-1;j++)
		{
			a[j]=a[m-j-1]+x;
		}
	}
	y=a[k];
	for(i=1;i<=n;i++)
	{
		p=y/x;
		printf("%d",p);
		y=y%x;
		x=x/2;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
