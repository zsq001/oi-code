#include <stdio.h>
#include <math.h>
int a[102],b[102];
int main()
{
	int n,type,min=0,sums=0;
	freopen("partition.in","r",stdin);
	freopen("partition.out","w",stdout);
	scanf("%d %d",&n,&type);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		b[i]=pow(a[i],2);
		min+=b[i];
	}
	/*for(int i=2;i<=n;i++)
	{
		int sum=0;
		if(a[i-1]>a[i])
		{
			int j=i+1;
			while(a[j-1]>a[j])
			{
				sum+=a[j-1];
				j+=1;
			}
			sums+=pow(2,sum);
			int ss=0;
			for(int k=j;k<=n;k++)
			  ss+=b[k];
			if(sums+ss<min) min=sums+ss;
			continue;
		}
		sums+=b[i];
	}
	if(sums<min) min=sums;*/
	printf("%d",min);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
