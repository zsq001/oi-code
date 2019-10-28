#include<stdio.h>
#include<stdlib.h>
int n,sum[200010];
double b[200010];
double abs(double a)
{
	if(a>0)
	{
		return a;
	}
	return -a;
}
double calc(double x)
{
	double tmp=0;
	int i,j;
	b[0]=0;
	for(i=1;i<=n;i++)
	{
		b[i]=sum[i]-i*x;
	}
	for(i=1;i<=n;i++)
	{
		for(j=i;j<=n;j++)
		{
			if(abs(b[j]-b[i-1])>tmp)
			tmp=abs(b[j]-b[i-1]);
		}
	}
	return tmp;
}
int main()
{
	freopen("seq.in","r",stdin);
	freopen("seq.out","w",stdout);
	int i,t;
	double ans,l=-0x7fffffff,r=0x7fffffff,mid,mmid,t1,t2;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%d",&t);
		sum[i]=sum[i-1]+t;
	}
	while(r-l>0.0000001)
	{
		mid=(l+r)/2;
		mmid=(mid+r)/2;
		t1=calc(mid);
		t2=calc(mmid);
		if(t1<t2)
		{
			r=mmid;
			ans=t1;
		}
		else
		{
			l=mid;
			ans=t2;
		}
	}
	printf("%.15lf",ans);
	return 0;
}
