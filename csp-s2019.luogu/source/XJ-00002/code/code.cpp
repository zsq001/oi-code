#include<stdio.h>
const int INF=1<<10;
long long int a[INF][64],n,m;
int main()
{
	freopen("code.in","r",stdin);
	freopen("code.out","w",stdout);
	long long int i,j,k,l;
	scanf("%lld%lld",&n,&m);
	int INE=1<<n;
	a[0][0]=0;
	a[1][0]=1;
	for(i=2,j=0;i<INE;i*=2)
	{
		for(k=i;k<i*2;k++)
		{
			for(l=0;l<=j;l++)
			{
				a[k][l]=a[i*2-k-1][l];
			}
			a[i*2-k-1][l]=0;
			a[k][l]=1;
		}
		j++;
	}
	for(i=n-1;i>=0;i--)
	{
		printf("%lld",a[m][i]);
	}
	printf("\n");
	fclose(stdin);
	fclose(stdout);
	return 0;
}
