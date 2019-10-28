#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<math.h>
#define max_ 100010.0
#define min_ -100010.0
using namespace std;
int n;
double a[200010],b[200010]={0.0};
double three(double x)
{
	b[1]=0.0;
	for(int i=1;i<=n;i++)
	{
		b[i]=a[i]-x;
		b[i]+=b[i-1];
	}
	double maxn=b[n];
	for(int i=0;i<=n;i++)
	{
		for(int j=i+1;j<=n;j++)
		{
			if(fabs(b[j]-b[i])>maxn) maxn=fabs(b[j]-b[i]);
		}
	}
	return maxn;
}
int main()
{
	freopen("seq.in","r",stdin);
	freopen("seq.out","w",stdout);
	double maxn=min_,minn=max_;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%lf",&a[i]);
		if(a[i]>maxn) maxn=a[i];
		if(a[i]<minn) minn=a[i];
	}
	double l=minn,r=maxn;
	while(r-l>=0.00000001)
	{
		double midl=(l+r)/2.0;
		double midr=(midl+r)/2.0;
		if(three(midl)>three(midr)) l=midl;
		else r=midr;
	}
	printf("%lf",three(l));
	fclose(stdin);
	fclose(stdout);
	return 0;
}
