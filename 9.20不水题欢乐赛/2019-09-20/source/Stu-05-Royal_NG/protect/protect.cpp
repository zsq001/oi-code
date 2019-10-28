#include<stdio.h>
#include<algorithm>
#include<math.h>
using namespace std;
int n;
double x=0.0,dis[10],minx=2147483647.0,maxn=-2147483648.0;
struct point{
	int x,y;
}a[10];
struct equal{
	int k2;
	double c,k1;
}b[10];
int main()
{
	freopen("protect.in","w",stdin);
	freopen("protect.out","r",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d%d",&a[i].x,&a[i].y);
	int t;
	if(a[1].x==a[2].x)
	{
		for(int i=1;i<n;i++)
			for(int j=i+1;j<=n;j++)
				if(a[i].y>a[j].y)
				{
					t=a[i].y;
					a[i].y=a[j].y;
					a[j].y=t;
				}
	}
	else
	{
		for(int i=1;i<n;i++)
			for(int j=i+1;j<=n;j++)
				if(a[i].x>a[j].x)
				{
					t=a[i].x;
					a[i].x=a[j].x;
					a[j].x=t;
					t=a[i].y;
					a[i].y=a[j].y;
					a[j].y=t;
				}
	}
	b[1].k1=0;b[1].k2=1;b[1].c=0;
	for(int i=2;i<=n;i++)
	{
		dis[i]=sqrt((a[i].x-a[i-1].x)*(a[i].x-a[i-1].x)+(a[i].y-a[i-1].y)*(a[i].y-a[i-1].y));
		b[i].k2=-b[i-1].k2;
		b[i].c=dis[i]-b[i-1].c;
		b[i].k1=b[i].c*2.0;
		if(b[i].k2>0)
		{
			double di=b[i].c*b[i].k2*(-1);
			if(di<minx)minx=di;
		}
		else if(b[i].k2<0)
		{
			double gao=b[i].c;
			if(gao>maxn)maxn=gao;
		}
	}
	double sk2=0.0,sk1=0.0,sc=0.0;
	for(int i=1;i<=n;i++)
	{
		sk2++;
		sc+=b[i].c*b[i].c;
		sk1+=1.0*b[i].k1*b[i].k2;
	} 
	x=sk1/((-2)*sk2);
	double lx=x-minx,rx=maxn-x;
	if(x>=minx&&x<=maxn)
	{
		if(lx>rx)x=minx;
		else x=maxn;
	}
	else if(x>maxn)
	{
		x=minx;
	}
	else x=maxn;
	//if(x>maxn&&maxn!=-2147483648)x=maxn;
	//else if(x<minx&&minx!=2147483647)x=minx;
	printf("%.2lf",x*x*sk2+x*sk1+sc);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
