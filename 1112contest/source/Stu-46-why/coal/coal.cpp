#include<cstdio>
#include<algorithm>
using namespace std;
int n,p,k,c;
double ans,w;
struct node{
	int id;
	int cost;
}a[100050];
void dfs(int now,double ma,double get)
{
	if(now>n)
	{
		if(get>ans)ans=get;
		return;
	}
	if(a[now].id==1)
	{
		dfs(now+1,ma*k/100,get+a[now].cost*ma);
		dfs(now+1,ma,get);
	}
	if(a[now].id==2)
	{
		if(get-a[now].cost*ma>0)dfs(now+1,ma+ma*k/100,get-a[now].cost*ma);
		dfs(now+1,ma,get);
	}
}
int main()
{
	freopen("coal.in","r",stdin);
	freopen("coal.out","w",stdout);
	scanf("%d%d%d%lf",&n,&k,&c,&w);
	int f=1;
	int maxx=-10;
	for(int i=1;i<=n;i++)
	{
		scanf("%d%d",&a[i].id,&a[i].cost);
	}
	if(k==100)
	{
		while(a[f].id!=2)
		{
			if(a[f].cost>maxx)
			{
				maxx=a[f].cost;
			}
			f++;
		}
		printf("%.2lf",w*maxx);
		return 0;
	}
	dfs(1,w,0);
	printf("%.2lf",ans);
}
