#include<stdio.h>
struct node{
			int last,to;
			double lon;
		   }e[2010];
int head[210],cnt,n,m;
double ans,min=2000.0;
void add(int u,int v,double x)
{
	cnt++;
	e[cnt].to=v;
	e[cnt].last=head[u];
	e[cnt].lon=x;
	head[u]=cnt;
}
void dfs(int u,int dep)
{
	if(u==n){				
				if(ans/dep<min)min=ans/dep;
				return;
			}
	for(int i=head[u];i!=0;i=e[i].last)
	{
		ans+=e[i].lon;
		dfs(e[i].to,dep+1);
		ans-=e[i].lon;
	}
}
int main()
{
	freopen("calabash.in","r",stdin);
	freopen("calabash.out","w",stdout);
	int u,v;
	double x;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++)
	{
		scanf("%d%d%lf",&u,&v,&x);
		add(u,v,x);
	}
	dfs(1,1);
	printf("%.3lf",min);
	fclose(stdin);
	
	return 0;
}
