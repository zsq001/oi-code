#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;

struct S
{
	int a,t;
}s[100010];
int n;
double x0=0.0,xm=0.0,v0=0.0,vm=0.0;

bool cmp(S x,S y)
{
	return x.a>y.a;
}

int main()
{
	freopen("physics.in","r",stdin);
	freopen("physics.out","w",stdout);

	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d%d",&s[i].a,&s[i].t);
		x0+=(double)v0*s[i].t+(double)(s[i].a*s[i].t*s[i].t)/2.0;
		v0+=(double)s[i].a*s[i].t;
	}
//	printf("%.1lf",x0);
	sort(s+1,s+1+n,cmp);
	for(int i=1;i<=n;i++)
	{
		xm+=(double)vm*s[i].t+(double)(s[i].a*s[i].t*s[i].t)/2.0;
		vm+=(double)s[i].a*s[i].t;
	}
	printf("%.1lf\n",xm-x0);
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
