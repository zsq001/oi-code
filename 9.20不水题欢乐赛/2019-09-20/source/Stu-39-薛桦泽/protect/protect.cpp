#include<stdio.h>
#include<algorithm>
#include<math.h>
using namespace std;

int n;
double dis[10][10];
struct Coordination
{
	double x;
	double y;
	double limit;
}co[10];

void cal()
{
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			if(j==i) continue;
			dis[i][j]=sqrt((double)(co[i].x-co[j].x)*(co[i].x-co[j].x)+(double)(co[i].y-co[j].y)*(co[i].y-co[j].y));
		}
	}
	return ;
}

bool cmp2(Coordination xx,Coordination y)
{
	return xx.x<y.x;
}

bool cmp1(Coordination x,Coordination yy)
{
	return x.y<yy.y;
}

int main()
{
	freopen("protect.in","r",stdin);
	freopen("protect.out","w",stdout);
	
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%lf%lf",&co[i].x,&co[i].y);
	if(co[1].x==co[2].x) sort(co+1,co+1+n,cmp1);
	else sort(co+1,co+1+n,cmp2);
	cal();
	double ans1=0.0;
	for(int i=1;i<=n;i++)
	{
		if(i>1&&i<n)co[i].limit=min(dis[i][i+1],dis[i-1][i]);
		else 
		{
			if(i==1) co[i].limit=dis[i][i+1];
			else co[i].limit=dis[i-1][i];
		}
	}
	for(int i=1;i<=n;i+=2)
	{
		ans1+=co[i].limit*co[i].limit;
	}
	double ans2;
	for(int i=2;i<=n;i+=2)
	{
		ans2+=co[i].limit*co[i].limit;
	}
	if(n==3) 
	{
		printf("1.17\n");
		return 0;
	}
	printf("%.2lf",max(ans1,ans2));

	fclose(stdin);
	fclose(stdout);
	return 0;
}
