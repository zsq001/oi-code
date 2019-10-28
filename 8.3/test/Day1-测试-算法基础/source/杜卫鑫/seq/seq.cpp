#include <stdio.h>
double max(double x,double y)
{
	return x>y?x:y;
}
double a[100],sum[100];
int n;
double fabs_(int x)
{
	if(x<0)return (-1)*x;
	else   return x;
}
double judge(double x)
{
	for(int i=1;i<=n;i++)
	{
		sum[i]=a[i];
		sum[i]-=x*i;
	}
	double res=0.000;
	for(int i=1;i<=n;i++)
		for(int j=0;j<i;j++)
		{
			res=max(fabs_(sum[i]-sum[j]),res);
		}
	return res;
}
int main()
{
//	freopen("seq.in","r",stdin);
//	freopen("seq.out","w",stdout);
	scanf("%d",&n);
	int t;
	if(n<=5)
	{
		for(int i=1;i<=n;i++)
		{
			scanf("%d",&t);
			a[i]=(double)t+a[i-1];
			sum[i]=sum[i-1]+t;
		}
		
		double l=0,r=5;
		while(r-l>=0.000001)
		{
			double mid=(l+r)/2.0;
			double mmid=(mid+r)/2.0;
			if(judge(mid)<judge(mmid))r=mmid;
			else                      l=mid;
		}
		printf("%.15lf",judge(l));
	}
	else
	{
		for(int i=1;i<=n;i++)
		{
			scanf("%d",&t);
			a[i]=(double)t+a[i-1];
			sum[i]=sum[i-1]+t;
		}
		double l=0,r=10000;
		while(r-l>=0.000000001)
		{
			double mid=(l+r)/2;
			double mmid=(mid+r)/2;
			if(judge(mid)<=judge(mmid))r=mmid;
			else                      l=mid;
		}
		printf("%.15lf",judge(l));
	}
//	fclose(stdin);
//	fclose(stdout);
	return 0;
}
