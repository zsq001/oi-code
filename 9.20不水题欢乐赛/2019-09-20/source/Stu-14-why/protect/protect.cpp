#include<cstdio>
#include<algorithm>
#include<cmath>
#include<cstring>
using namespace std;
int n;
double x[10];
double y[10];
double k,b1;
double minn[10];
double mmin=10000;
double maxx;
double a,b,c,ansa,ansb,ansc;
double ans;
double tx,tn,no;
using namespace std;
int main()
{
	for(int i=1;i<=10;i++)
	{
		minn[i]=1000000;
	}
	freopen("protect.in","r",stdin);
	freopen("protect.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%lf%lf",&x[i],&y[i]);
	}
	if(n==2)
	{
		ans=(y[2]-y[1])*(y[2]-y[1])+(x[2]-x[1])*(x[2]-x[1]);
		ans=sqrt(ans);
		ans/=2;
		printf("%.2lf",2*ans*ans);
		return 0;
	}
	if(n==3)
	{
		if(x[2]!=0&&x[1]!=0)
		{
			k=(y[2]-y[1])/(x[2]-x[1]);
		}
		else if(x[3]==0)
		{
			k=-1;
		}
		if(k!=-1)
		{
			if((y[3]-y[1])/(x[3]-x[1])==k);
		
		else
		{
		maxx=0;
		a=(y[2]-y[1])*(y[2]-y[1])+(x[2]-x[1])*(x[2]-x[1]);
		b=(y[3]-y[1])*(y[3]-y[1])+(x[3]-x[1])*(x[3]-x[1]);
		c=(y[2]-y[3])*(y[2]-y[3])+(x[2]-x[3])*(x[2]-x[3]);
		a=sqrt(a);
		b=sqrt(b);
		c=sqrt(c);
		if(a<mmin)
		{
			mmin=a;
			tn=a;
		}
		if(b<mmin)
		{
			mmin=b;
			tn=b;
		}
		if(c<mmin)
		{
			mmin=c;
			tn=c;
		}
		if(a>maxx)
		{
			maxx=a;
			tx=a;
		}
		if(b>maxx)
		{
			maxx=b;
			tx=b;
		}
		if(c>maxx)
		{
			maxx=c;
			tx=c;
		}
		if(tx!=a&&tn!=a)
		{
			no=a;
		}
		if(tx!=b&&tn!=b)
		{
			no=b;
		}
		if(tx!=c&&tn!=c)
		{
			no=c;
		}
		printf("%.2lf",mmin*mmin+(maxx-mmin)*(maxx-mmin)+(no-mmin)*(no-mmin));
		return 0;
		}
		}
	}
	if(x[2]!=0&&x[1]!=0)
	{
		k=(y[2]-y[1])/(x[2]-x[1]);
		b1=y[1]-k*x[1];
	}
	sort(x+1,x+n+1);
	if(x[2]!=0&&x[1]!=0)
	{
		for(int i=1;i<=n;i++)
		{
			y[i]=k*x[i]+b1;
		}
	}
	else if(x[1]==0&&x[2]==0)
	{
		sort(y+1,y+n+1);
	}
	for(int i=1;i<=n;i+=2)
	{
		for(int j=1;j<=n;j++)
		{
			if(j!=i)
			{
				if(((y[j]-y[i])*(y[j]-y[i])+(x[j]-x[i])*(x[j]-x[i]))<minn[i])
				{
					minn[i]=(y[j]-y[i])*(y[j]-y[i])+(x[j]-x[i])*(x[j]-x[i]);
				}
			}
			
		}
	}
	for(int i=1;i<=n;i+=2)
	{
		ans+=minn[i];
	}
	printf("%.2lf",ans);
	return 0;
}
