#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
#define maxn 100010
using namespace std;

int n;
double s1,s2,lastv1,lastv2;
struct sp
{
	double a,t;
}sep[maxn];

void INIT(double x,double y)
{
	lastv1=(double)lastv1+x*y;
	s1=(double)(s1+lastv1*y+0.5*x*y*y);
}

void cal(double x,double y)
{
	lastv2=(double)lastv2+x*y;
	s2=(double)(s2+lastv2*y+0.5*x*y*y);
}

bool cmp (sp a1,sp a2)
{
	return a1.a>a2.a;
}

int main()
{
	freopen("physics.in","r",stdin);
	freopen("physics.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		double x,y;
		scanf("%lf%lf",&x,&y);
		INIT(x,y);
		sep[i].a=x;sep[i].t=y;
	}
	sort(sep+1,sep+1+n,cmp);
	for(int i=1;i<=n;i++)
	{
		cal(sep[i].a,sep[i].t);
	}
	double ans=s2-s1;
	printf("%.1lf\n",ans);
	return 0;	
}
