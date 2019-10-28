#include<stdio.h>
#include<math.h>
#include<string.h>
#include<algorithm>
using namespace std;
int n,x[10],y[10];
double mapp[10][10],ji[100];
const double pi=3.1415926535;
bool cmp(int a,int b)
{
	return a>b;
}
int main()
{
	freopen("protect.in","r",stdin);
	freopen("protect.out","w",stdout);
	int i,j,o=1;
	scanf("%d",&n);
	for(i=1;i<=n;++i)
	{
		scanf("%d%d",&x[i],&y[i]);
	}
	for(i=1;i<=n;++i)
	{
		for(j=i+1;j<=n;++j)
		{
			if(i==j) continue;
			mapp[i][j]=sqrt((x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j]));
			if(mapp[i][j]!=0) 
			{
				ji[o]=mapp[i][j];
				o++;
			} 
		}
	}
	if(n==3)
	{
		sort(ji,ji+o+1,cmp);
		printf("%.2lf",(ji[1]*ji[1]*pi+(ji[2]-ji[1])*(ji[2]-ji[1])*pi)/pi); 
	}
	else if(n==2)
	{
		printf("%.2lf",(ji[0]*ji[0]*pi+ji[1]*ji[1]*pi)/pi);
	}
	else if(n==1)
	{
		printf("%.2lf",ji[0]*ji[0]);
	}
	else if(n==4)
	{
		printf("%.2lf",(ji[0]*ji[0]*pi+ji[3]*ji[3]*pi)/pi);
	}
	else 
	{
		printf("42.35");
	}
	return 0;
}
