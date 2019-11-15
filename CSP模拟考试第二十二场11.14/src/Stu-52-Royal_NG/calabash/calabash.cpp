#include<stdio.h>
struct edge{
	int v,last,w;
}a[3000];
int first[1000],tot;
void add(int u,int v,int w)
{
	a[++tot].last=first[u];
	a[tot].v=v;
	a[tot].w=w;
	first[u]=tot;
}
int main()
{
	freopen("calabash.in","r",stdin);
	freopen("calabash.out","w",stdout);
	int n,m;
	scanf("%d%d",&n,&m);
	if(n==2&&m==1)
	{
		int u,v,w;
		scanf("%d%d%d",&u,&v,&w);
		double f=1.0*w;
		printf("%.3lf",f);
	}
	else if(n-m==1)
	{
		for(int i=1;i<=m;i++)
		{
			int u,v,w;
			scanf("%d%d%d",&u,&v,&w);
			add(v,u,w);
		}
		int now=n,num=0;
		double ans=0.0;
		for(int i=first[n];first[i];i=first[a[i].v])
			ans+=1.0*a[i].w,num++;
		printf("%.3lf",ans/(1.0*num));
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
